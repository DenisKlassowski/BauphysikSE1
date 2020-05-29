class TabData:
    def __init__(self, mode, layers, rsi=0.0, rse=0.0, rges=0.0, rt=0.0, tin=0.0, tout=0.0, u=0.0):
        self.layers = layers
        self.rsi = rsi
        self.rse = rse
        self.rges = rges
        self.tin = tin
        self.tout = tout
        self.mode = mode
        self.u = u
        self.rt = rt
