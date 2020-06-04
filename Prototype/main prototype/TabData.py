import Calculation

class TabData:
    def __init__(self, mode, name, layers=[], rsi=0.0, rse=0.0, rges=0.0, rt=0.0, tin=0.0, tout=0.0, u=0.0):
        self.name = name
        self.layers = layers
        self.rsi = rsi
        self.rse = rse
        self.rges = rges
        self.tin = tin
        self.tout = tout
        self.mode = mode
        self.u = u
        self.rt = rt

    def add_layer(self, layer):
        self.layers.append(layer)

    def pop_layer(self, index):
        return self.layers.pop(index)

    def remove_layer(self, index):
        l=self.pop_layer(index)
        del l

    def move_layer(self, indexFrom, indexTo):
        if indexFrom<=indexTo:
            self.insert_layer(self.pop_layer(indexFrom),indexTo)
        else:
            self.insert_layer(self.pop_layer(indexFrom),indexTo-1)

    def insert_layer(self, layer, index):
        self.layers.insert(index, layer)

    def calculate(self):
        Calculation.tab_calc(self)
