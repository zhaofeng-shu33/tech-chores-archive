#!/usr/bin/python
# -*- coding: utf-8 -*-
# author: zhaofeng-shu33
# license: Apache License Version 2.0
# created: 2018/5/5
# file-description: accomplish tasks with opencv-python
# reference: http://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials
import cv2
import pdb
import argparse
import numpy as np
import matplotlib.pyplot as plt
import logging
from alignment import alignPair
import os
import blend
image_main_directory = ''
sift = cv2.xfeatures2d.SIFT_create()
bf = cv2.BFMatcher()
class ImageWrapper:
    def __init__(self, img_name, isWrite = False):
        '''
          if isWrite is True, we do not check that whether the image exists.
        '''
        self.img_path  = os.path.join(image_main_directory, img_name)
        if(isWrite):
            self.data = None
            return
        if(os.path.isfile(self.img_path)):
            self.data = cv2.imread(self.img_path)
        else:            
            raise FileNotFoundError('%s not found'%self.img_path)

    def write(self, file_name = ''):
        if(file_name):
            self.img_path  = os.path.join(image_main_directory, file_name)       
        img_name = os.path.split(self.img_path)[-1]     
        if not(img_name.endswith('.jpg') or img_name.endswith('.png')):
            raise Exception("Invalid image name.")
        cv2.imwrite(self.img_path, self.data)

    def extract_features(self, method = 'sift'):
        '''
          extract features using given method
        '''
        if(method == 'sift'):
            try:
                self.keypoints, self.descriptors = sift.detectAndCompute(cv2.cvtColor(self.data, cv2.COLOR_BGR2GRAY), None)
            except cv2.error as e:
                logging.error('extracting features from %s encounters error with method %s' %(self.img_path, method))
                raise e
        else:
            raise NotImplementedError("method %s not implemented"%method)
    def show(self):
        plt.imshow(self.data)
        plt.show()

def join_two_images(image_wrapper_1_name, image_wrapper_2_name, joined_image_write_name):
    image_wrapper_1 = ImageWrapper(image_wrapper_1_name)
    image_wrapper_1.extract_features()
    image_wrapper_2 = ImageWrapper(image_wrapper_2_name)
    image_wrapper_2.extract_features()
    joined_image_wrapper  = _join_two_images(image_wrapper_1, image_wrapper_2)
    joined_image_wrapper.show()
    joined_image_wrapper.write(joined_image_write_name)
    
def _join_two_images(left_image_wrapper, right_image_wrapper, use_full_homography = 1):
    '''
    two images alignment task
    left image <-> right image

    Parameters    
    ----------
    left_image_wrapper : ImageWrapper
    right_image_wrapper : ImageWrapper
    use_full_homography : bool
        when false, the homography is restricted to translation

    Returns
    -------
    joined_image_wrapper : ImageWrapper
    '''

    #********knn feature matching********
    # the original literature used k-d tree search
    # but for this small task
    # we do not need this
    # use brute force matcher instead
    # opencv provides Fast Library for Approximate Nearest Neighbors which support k-d tree search
    # reduces the time complexity to O(n log(n))
    matches = bf.knnMatch(left_image_wrapper.descriptors, right_image_wrapper.descriptors, k=2)
    # Apply ratio test
    good = []
    for m,n in matches:
        if m.distance < 0.75*n.distance:
            good.append(m)
    
    # use functions written by others to compute homography, which is 3 times 3 matrix
    # the homography is from left image to right image 
    mapping = alignPair(left_image_wrapper.keypoints, right_image_wrapper.keypoints,\
     good, use_full_homography, 500, 5.0)    
    height, width, _ = right_image_wrapper.data.shape
    height_l, width_l, _ = left_image_wrapper.data.shape
    mapping = np.linalg.inv(mapping)
    mapping /= mapping[2, 2]

    points = np.array([
        [0, 0, 1],
        [width, 0, 1],
        [0, height, 1],
        [width, height, 1],
    ], dtype=float)
    points_l = np.array([[0,0,1],[width_l, 0, 1],[0, height_l, 1], [width_l, height_l, 1]], dtype = float)
    trans_points = np.dot(mapping, points.T).T  
    trans_points /= trans_points[:, 2][:, np.newaxis]

    all_points = np.vstack([points_l, points, trans_points])

    minX = np.min(all_points[:, 0])
    maxX = np.max(all_points[:, 0])
    minY = np.min(all_points[:, 1])
    maxY = np.max(all_points[:, 1])

    # Create an accumulator image
    newWidth = int(np.ceil(maxX) - np.floor(minX))
    newHeight = int(np.ceil(maxY) - np.floor(minY))

    translation = np.array([[1.0, 0, -minX], [0, 1, -minY], [0, 0, 1.0]])

    warpedRightImage = cv2.warpPerspective(
        right_image_wrapper.data, np.dot(translation, mapping), (newWidth, newHeight)
    )
    warpedRightImage[int(-minY):int(height_l - minY), int(-minX):int(width_l - minX),:] = left_image_wrapper.data

    joined_image_wrapper = ImageWrapper('', isWrite = True)
    joined_image_wrapper.data = warpedRightImage    
    return joined_image_wrapper
        
def join_multiple_images(image_file_list, out_img_name = '', use_full_homography = False): # only translation is considered
    # the first image is used as anchor
    anchor_image_wrapper = ImageWrapper(image_file_list[1])
    logging.info("use image %s as anchor"%anchor_image_wrapper.img_path)
    # the first image is removed from the list
    image_file_list.pop(1)     
    image_wrapper_list = []
    for i in image_file_list:
        image_wrapper_tmp = ImageWrapper(i)
        image_wrapper_tmp.extract_features()
        image_wrapper_list.append(image_wrapper_tmp)
    while(len(image_wrapper_list)>=1):
        score=[]
        anchor_image_wrapper.extract_features()        
        # choose the matched image with highest score
        for i in image_wrapper_list:
            matches = bf.knnMatch(anchor_image_wrapper.descriptors, i.descriptors, k=2)
            good = []
            for m,n in matches:
                if m.distance < 0.75*n.distance:
                    good.append(m)
            score.append(len(good))
        max_score = max(score)
        max_score_index = score.index(max_score)
        matched_image_wrapper = image_wrapper_list.pop(max_score_index) 
        logging.info('joining %s'%matched_image_wrapper.img_path)
                   
        # begin matching
        anchor_image_wrapper = _join_two_images(anchor_image_wrapper, matched_image_wrapper, use_full_homography)
    if(out_img_name):
        anchor_image_wrapper.write(out_img_name)

# author: conscho and CharlieLaBarge        
def computeMapping(leftImage, rightImage):
    '''
       compute the homography from leftImage to rightImage
    '''
    leftGrey = cv2.cvtColor(leftImage, cv2.COLOR_BGR2GRAY)
    rightGrey = cv2.cvtColor(rightImage, cv2.COLOR_BGR2GRAY)
    orb = cv2.ORB_create()
    leftKeypoints, leftDescriptors = orb.detectAndCompute(leftGrey, None)
    rightKeypoints, rightDescriptors = orb.detectAndCompute(
        rightGrey, None
    )
    bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
    matches = bf.match(leftDescriptors, rightDescriptors)
    matches = sorted(matches, key=lambda x: x.distance)

    nMatches = int(
        20 * len(matches) / 100
    )

    if nMatches < 4:
        return None

    matches = matches[:nMatches]
    motionModel = 1
    nRANSAC = 500
    RANSACThreshold = 5.0

    return alignPair(
        leftKeypoints, rightKeypoints, matches, motionModel, nRANSAC,
        RANSACThreshold
    )

# author: conscho and CharlieLaBarge        
def join_multiple_images_others(image_file_list, out_img_name = ''):         
    processedImages = [cv2.imread(os.path.join(image_main_directory,i)) for i in image_file_list]
    t = np.eye(3)
    ipv = []
    for i in range(0, len(processedImages) - 1):
        logging.info(
            'Computing mapping from {0} to {1}'.format(i, i+1)
        )
        ipv.append(
            blend.ImageInfo('', processedImages[i], np.linalg.inv(t))
        )
        t = computeMapping(
            processedImages[i], processedImages[i+1]
        ).dot(t)

    ipv.append(blend.ImageInfo(
        '', processedImages[len(processedImages)-1], np.linalg.inv(t))
    )

    t = computeMapping(
        processedImages[len(processedImages)-1],
        processedImages[0]
    ).dot(t)

    logging.info('Blending Images')
    image_stitched = blend.blendImages(
        ipv,50,
        False
    )
    logging.info('Panorama generated')
    if(out_img_name):
        cv2.imwrite(os.path.join(image_main_directory, out_img_name), image_stitched)
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--debug', action = 'store_true')
    parser.add_argument('--fig', help = 'set image main directory', default = 'image-stitching')
    parser.add_argument('--task', choices = ['task_1_1', 'task_1_2', 'task_1_3', 'self', 'orb'], default = 'task_1_1',\
    help ="task_1_[1-3] is for stitching given image files, self is used for stitching self-prepared image files,\
    and orb is used for using orb key points extraction method.")
    args = parser.parse_args()
    if(args.debug):
        pdb.set_trace()
        logging.basicConfig(level = logging.DEBUG)
    else:
        logging.basicConfig(level = logging.INFO)
    image_main_directory = args.fig

    if(args.task == 'task_1_1'):
        join_two_images('(2).jpg', '(1).jpg', 'task_1_1.png')        
    elif(args.task == 'task_1_2'):
        join_two_images('1.JPG', '2.JPG', 'task_1_2.png')
    elif(args.task == 'task_1_3'): # This task is cylinder image stiching, only considering X axis translation.
        image_list = ['01.jpg', '02.jpg', '03.jpg', '04.jpg', '05.jpg', '06.jpg', '07.jpg', '08.jpg', '09.jpg', '10.jpg', '11.jpg', '12.jpg']
        join_multiple_images(image_list, 'task_1_3.png')
    elif(args.task == 'self'):
        image_list = ['p989.jpg', 'p990.jpg', 'p991.jpg']
        join_multiple_images(image_list, 'self.png', use_full_homography = True)
    elif(args.task == 'orb'):
        image_list = ['p989.jpg', 'p990.jpg', 'p991.jpg']
        join_multiple_images_others(image_list, 'orb.png')
