import Calculation
from TabData import TabData
from LayerData import LayerData
from Exporter import Exporter
from Parser import Parser


class Export:

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
        self.tab = TabData(0, "Test_032")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13
        self.tab.tright = 21
        self.tab.tleft = 4

        # Schichten in Tab hinzufügen
        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)
        self.tab.add_layer(self.layer_3)
        self.tab.add_layer(self.layer_4)

        self.tab.calculate()

        self.Export = Exporter(self.tab)
        self.parser = Parser(str("TestExport.baup"))


if __name__ == '__main__':
        obj = Export()
        obj.Export.export("TestExport")
        newtab = obj.parser.parse()
        print(obj.tab.rright)
        print(newtab.rright)
        print(obj.tab.rleft)
        print(newtab.rleft)
        print(obj.tab.tright)
        print(newtab.tright)
        print(obj.tab.tleft)
        print(newtab.tleft)
        print(len(newtab.layers))
        print(float(newtab.layers[0].lambda_))
