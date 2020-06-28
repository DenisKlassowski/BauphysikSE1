from LayerData import LayerData
from TabData import TabData

class Test:


    def __init__(self):
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 0
        self.layer_1.width = 0.175
        self.layer_1.lambda_ = 0.36

        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 0
        self.layer_2.width = 0.150
        self.layer_2.lambda_ = 0.03

        self.layer_3 = LayerData()
        self.layer_3.widthUnit = 0
        self.layer_3.width = 0.115
        self.layer_3.lambda_ = 1.20

        self.tab = TabData(1, "Test_022")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13
        self.tab.tright = -4
        self.tab.tleft = 19

        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)
        self.tab.add_layer(self.layer_3)


if __name__ == '__main__':
    objekt = Test()
    """
    print(objekt.layer_2.width)
    print(objekt.layer_2.lambda_)
    print(objekt.layer_2.r)
    objekt.layer_2.calculate()
    print(round(objekt.layer_2.r,5))
    """

    print(objekt.tab.rsum)
    print(objekt.tab.rt)
    print(objekt.tab.u)
    objekt.tab.calculate()
    print(objekt.tab.rsum)
    print(objekt.tab.rt)
    print(objekt.tab.u)
    print(objekt.tab.tright)
    print(objekt.tab.tleft)
    print(objekt.tab.layers[0].t_left)
    print(round(objekt.tab.layers[0].t_left, 2))
    print(round(objekt.tab.layers[0].t_right, 2))
    print(round(objekt.tab.layers[1].t_left, 2))
    print(round(objekt.tab.layers[1].t_right, 2))
    print(round(objekt.tab.layers[2].t_left, 2))
    print(round(objekt.tab.layers[2].t_right, 2))

