# This Python file uses the following encoding: utf-8
import Calculation


class LayerData:
    def __init__(self, name=None, mat=None, r=None, lambda_=None, width=None, widthUnit=None):
        #some trickery because default values in the constructor call kind of destroy the the possibility to have multiple instances of the same class. Why? Python, that's why. further information: https://stackoverflow.com/questions/4841782/python-constructor-and-default-value
        #In contrast to TabData, LayerData was fine with multiple instances. I do not know why. I have changed it just in case
        self.width = width if width is not None else 0.0
        """width in metric units"""
        # 0: m, 1: cm, 2: mm
        self.widthUnit = widthUnit if widthUnit is not None else 0
        """unit of width measurement; 0: m, 1:cm, 2: mm"""
        self.lambda_ = lambda_ if lambda_ is not None else 0.0
        """lambda in metric unit"""
        self.r = r if r is not None else 0.0
        """R of layer"""
        self.t_left = 0.0
        """temperature left of layer: if imagining the layers vertically from left to right (first layer is the left-most layer and vice versa) that is the temperature between this layer and the previous one (if this is the first layer, it is the temp between this one and the environment)"""
        self.t_right = 0.0
        """same as t_left, only the right side of the layer is meant this time"""
        self.rho = 0.0
        """rho"""
        self.name = name if name is not None else ""
        """name of layer"""
        self.mat = mat if mat is not None else 0
        """material ID _currently not in use_"""

    def calculate(self):
        """calculate R for layer"""
        Calculation.layer_calc(self)

    def calculate_lambda(self):
        """calculate lambda for layer"""
        Calculation.calc_lambda(self)
