class StringList(list):
    def __init__(self,iterable=[]):
        super(StringList,self).__init__(iterable)
    def append(self,item):
        if not (isinstance(item,type('a')) or isinstance(item,type(u'a'))):
            raise TypeError,'item is not of type str'
        super(StringList,self).append(item)
    def search(self,item):
        if not (isinstance(item,type('a')) or isinstance(item,type(u'a'))):
            raise TypeError,'item is not of type str'
        low=0;
        high=super(StringList,self).__len__();
        while(low<high):
            middle=(high-low)/2+low;
            if(super(StringList,self).__getitem__(middle)==item):
                return middle;
            elif(super(StringList,self).__getitem__(middle)>item):
                high=middle;
            else:
                low=middle+1;
        return -1;
    def __len__(self): return super(StringList,self).__len__()


