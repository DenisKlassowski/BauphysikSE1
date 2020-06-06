# This Python file uses the following encoding: utf-8
import Calculation


class LayerData:
    def __init__(self, mat=0, r=0.0000, lambda_=0.000, width=0.000, widthUnit=0):
        self.width = width
        # 0: m, 1: cm, 2: mm
        self.widthUnit = widthUnit
        self.lambda_ = lambda_
        self.r = r
        self.t_left = 0.0
        self.t_right = 0.0
        self.rho = 0.0
        self.mat = mat

    def calculate(self):
        Calculation.layer_calc(self)
