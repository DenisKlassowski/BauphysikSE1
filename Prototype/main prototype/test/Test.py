from LayerData import LayerData
from TabData import TabData

class Test:

    def __init__(self):
        # erstelle erste Schicht
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 1
        self.layer_1.width = 36.5
        self.layer_1.lambda_ = 0.72

        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 1
        self.layer_2.width = 2
        self.layer_2.lambda_ = 0.87

        self.tab = TabData(0, "Test_024")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13

        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)


if __name__ == '__main__':
    objekt = Test()
    """
    print(objekt.layer_5.width)
    print(objekt.layer_5.lambda_)
    print(objekt.layer_5.r)
    objekt.layer_5.calculate()
    print(objekt.layer_5.r)
    """

    print(objekt.tab.rsum)
    print(objekt.tab.rt)
    print(objekt.tab.u)
    objekt.tab.calculate()
    print(objekt.tab.rsum)
    print(objekt.tab.rt)
    print(objekt.tab.u)
