
class Calculation:
    def __init__(self, layers, rsi, rse):
        self.layers = layers
        self.rsi = rsi
        self.rse = rse

    def calc_r(self):
        r = 0
        for layer in self.layers:
            r += layer.width / layer.lambda_
        return r

    def calc_rt(self):
        rt = self.rsi + self.rse + self.calc_r()
        return rt

    def calc_u(self):
        u = 1 / self.calc_rt()
        return u

