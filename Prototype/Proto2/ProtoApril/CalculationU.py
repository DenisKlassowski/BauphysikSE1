import Calculation


class CalculationU(Calculation):
    def __init__(self, layers, rsi, rse):
        self.layers = layers
        self.rsi = rsi
        self.rse = rse

    # returns RT
    def calc_rt(self):
        rt = self.rsi + self.rse + self.calc_r()
        return rt

    # returns Uw
    def calc_u(self):
        u = 1 / self.calc_rt()
        return u
