# This Python file uses the following encoding: utf-8


class LayerData:
    def __init__(self, r, lambda_, width):
        self.width = width
        self.lambda_ = lambda_
        self.r = r
        self.t_inside = 0.0
        self.t_outside = 0.0
        self.rho = 0.0
