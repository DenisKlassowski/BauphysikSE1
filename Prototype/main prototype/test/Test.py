from LayerData import LayerData
from TabData import TabData

class Test:

    def __init__(self):
        # erstelle erste Schicht
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 1
        self.layer_1.width = 0.02
        self.layer_1.lambda_ = 0.350

        # erstelle zweite Schicht
        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 1
        self.layer_2.width = 0.24
        self.layer_2.lambda_ = 0.560

        # erstelle dritte Schicht
        self.layer_3 = LayerData()
        self.layer_3.widthUnit = 1
        self.layer_3.width = 0.05
        self.layer_3.lambda_ = 0.045

        # erstelle vierte Schicht
        self.layer_4 = LayerData()
        self.layer_4.widthUnit = 1
        self.layer_4.width = 0.01
        self.layer_4.lambda_ = 0.700

        # erstelle Tab
        self.tab = TabData(0, "Test_021")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13

        # Schichten in Tab hinzufügen
        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)
        self.tab.add_layer(self.layer_3)
        self.tab.add_layer(self.layer_4)


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
