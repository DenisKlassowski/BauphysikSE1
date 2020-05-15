
class Calculation:
    def __init__(self, layers, rsi, rse, r_ges = 0):
        self.layers = layers
        self.rsi = rsi
        self.rse = rse
        if r_ges == 0:
            self.r_ges = self.calc_r()

    # returns full R
    def calc_r(self):
        r = 0
        for layer in self.layers:
            r += layer.width / layer.lambda_
        return r
