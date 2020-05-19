import copy
class Menge(object):
    def __init__(self,newList=[]):
        self.data=[]
        for item in newList:
            self.insert(item)
    def __getitem__(self,item):
        if item>=len(self.data):
            raise IndexError;
        return self.data[item]
    
    def get_data(self):
        return self.data

    def contains(self,member):
        for item in self.data:
            if item==member:               
                return True
        return False

    def insert(self,member):
        
        if(not(self.contains(member))):
            self.data.append(member)
            return True
        else:
            return False

    def remove(self,item):
        if(self.contains(item)):
            self.data.remove(item)
            return True
        else:
            return False
    def union(self,Menge2):
        for item in Menge2:
            self.insert(item)

    def subtract(self,Menge2):
        for item in Menge2:
            self.remove(item)

    def intersect(self,Menge2):
        Menge3=copy.deepcopy(Menge2)
        Menge2.subtract(self)
        Menge3.subtract(Menge2)
        self.data=Menge3.data

    def isEmpty(self):
        return len(self.data)==0

    def getSize(self):
        return len(self.data)
    
        
    
    
