import numpy as np
import torch
import torchvision.models as models
from torchvision import transforms
from torchvision.datasets import CIFAR10

googlenet = models.googlenet(pretrained=True, progress=True)
feature_model = torch.nn.Sequential(*list(googlenet.children())[0:18])

preprocess = transforms.Compose([
    transforms.Resize(224),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
])

train_data = CIFAR10('./data', train=True, transform=preprocess, download=True)
test_data = CIFAR10('./data', train=False, transform=preprocess, download=True)

batch_size = 100
train_data_loader = torch.utils.data.DataLoader(train_data, batch_size=batch_size, shuffle=False)
test_data_loader = torch.utils.data.DataLoader(test_data, batch_size=batch_size, shuffle=False)

train_data_holder = torch.zeros([50000, 1024], dtype=torch.float32)
test_data_holder = torch.zeros([10000, 1024], dtype=torch.float32)

def fill_data_holder(data_loader, data_holder):
    n, _ = data_holder.shape
    for i, data in enumerate(data_loader):
        inputs, _ = data
        with torch.no_grad():
            data_feature = feature_model(inputs)
        data_holder[i * batch_size:(i + 1) * batch_size, :] = data_feature.view(-1,1024)
        print(f'{i * batch_size}/{n}')

def save_data(data_holder, target_name):
    np_array = data_holder.detach().numpy()
    np.save(target_name, np_array)

fill_data_holder(train_data_loader, train_data_holder)
fill_data_holder(test_data_loader, test_data_holder)
save_data(train_data_holder, 'train_feature_1024_cifar10.npy')
save_data(train_data_holder, 'test_feature_1024_cifar10.npy')
