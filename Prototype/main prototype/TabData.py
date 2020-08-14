import Calculation
from LayerData import LayerData

class TabData:
    def __init__(self, mode, name, layers=None, rright=None, rleft=None, rsum=None, rt=None, tright=None, tleft=None, u=None, currentFileLocation=None):
        #some trickery because default values in the constructor call kind of destroy the the possibility to have multiple instances of the same class. Why? Python, that's why. further information: https://stackoverflow.com/questions/4841782/python-constructor-and-default-value
        self.name = name
        """title of tab"""
        self.layers = layers if layers is not None else map(LayerData,[])
        """list of layers in current tab"""
        self.rright = rright if rright is not None else 0.0
        """if imagining the layers vertically, this is the R which is adjacent to the right-most layer"""
        self.rleft = rleft if rleft is not None else 0.0
        """same as rright, only this time you have to think to the left"""
        self.rsum = rsum if rsum is not None else 0.0
        """sum of all the layers' R's"""
        self.tright = tright if tright is not None else 0.0
        """same as rright, this time it's the temperature"""
        self.tleft = tleft if tleft is not None else 0.0
        """same as tright, this time it's to the left"""
        self.mode = mode
        """mode of tab"""
        self.u = u if u is not None else 0.0
        """inverse of rt"""
        self.rt = rt if rt is not None else 0.0
        """sum of rsum and rright and rleft"""
        self.currentFileLocation = currentFileLocation if currentFileLocation is not None else None
        """current save path if there is one"""

    def add_layer(self, layer):
        """add layer (data) to the list of layers"""
        self.layers.append(layer)

    def pop_layer(self, index):
        """remove layer (data) from the layer list at given index and return it"""
        return self.layers.pop(index)

    def remove_layer(self, index):
        """remove layer (data) from layer list at given index"""
        l = self.pop_layer(index)
        del l

    def move_layer(self, indexFrom, indexTo):
        """move ("drag and drop") a layer from position x to position y"""
        if indexFrom <= indexTo:
            self.insert_layer(self.pop_layer(indexFrom), indexTo)
        else:
            self.insert_layer(self.pop_layer(indexFrom), indexTo - 1)

    def insert_layer(self, layer, index):
        """insert layer (data) at given index"""
        self.layers.insert(index, layer)

    def reverse_layers(self):
        """reverse the list of layers (data)"""
        self.layers.reverse()

    def calculate(self):
        """calculate the tab"""
        try:
            Calculation.tab_calc(self)
        except ZeroDivisionError:
            raise ZeroDivisionError
