# This Python file uses the following encoding: utf-8
import Calculation


class LayerData:
    def __init__(self, name=None, mat=None, r=None, lambda_=None, width=None, widthUnit=None):
        #some trickery because default values in the constructor call kind of destroy the the possibility to have multiple instances of the same class. Why? Python, that's why. further information: https://stackoverflow.com/questions/4841782/python-constructor-and-default-value
        #In contrast to TabData, LayerData was fine with multiple instances. I do not know why. I have changed it just in case
        self.width = width if width is not None else 0.0
        # 0: m, 1: cm, 2: mm
        self.widthUnit = widthUnit if widthUnit is not None else 0
        self.lambda_ = lambda_ if lambda_ is not None else 0.0
        self.r = r if r is not None else 0.0
        self.t_left = 0.0
        self.t_right = 0.0
        self.rho = 0.0
        self.name = name if name is not None else ""
        self.mat = mat if mat is not None else 0

    def calculate(self):
        Calculation.layer_calc(self)

    def calculate_lambda(self):
        Calculation.calc_lambda(self)
