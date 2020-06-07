import Calculation


class TabData:
    def __init__(self, mode, name, layers=None, rright=None, rleft=None, rsum=None, rt=None, tright=None, tleft=None, u=None):
        #some trickery because default values in the constructor call kind of destroy the the possibility to have multiple instances of the same class. Why? Python, that's why. further information: https://stackoverflow.com/questions/4841782/python-constructor-and-default-value
        self.name = name
        self.layers = layers if layers is not None else []
        self.rright = rright if rright is not None else 0.0
        self.rleft = rleft if rleft is not None else 0.0
        self.rsum = rsum if rsum is not None else 0.0
        self.tright = tright if tright is not None else 0.0
        self.tleft = tleft if tleft is not None else 0.0
        self.mode = mode
        self.u = u if u is not None else 0.0
        self.rt = rt if rt is not None else 0.0

    def add_layer(self, layer):
        self.layers.append(layer)

    def pop_layer(self, index):
        return self.layers.pop(index)

    def remove_layer(self, index):
        l = self.pop_layer(index)
        del l

    def move_layer(self, indexFrom, indexTo):
        if indexFrom <= indexTo:
            self.insert_layer(self.pop_layer(indexFrom), indexTo)
        else:
            self.insert_layer(self.pop_layer(indexFrom), indexTo - 1)

    def insert_layer(self, layer, index):
        self.layers.insert(index, layer)

    def reverse_layers(self):
        self.layers.reverse()

    def calculate(self):
        try:
            Calculation.tab_calc(self)
        except ZeroDivisionError:
            raise ZeroDivisionError
