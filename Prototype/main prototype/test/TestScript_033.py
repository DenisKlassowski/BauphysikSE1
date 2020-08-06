import unittest

from Exporter import Exporter
from LayerData import LayerData
from TabData import TabData
from Parser import Parser

class TestScript_033(unittest.TestCase):
    """
    Test von Export&Import mit den Daten für 4 Schichten
    analog manuellem TestScript_020
    """
    def setUp(self):
        #erstelle erste Schicht
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 1
        self.layer_1.width = 0.02
        self.layer_1.lambda_ = 0.350

        #erstelle zweite Schicht
        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 1
        self.layer_2.width = 0.24
        self.layer_2.lambda_ = 0.560

        #erstelle dritte Schicht
        self.layer_3 = LayerData()
        self.layer_3.widthUnit = 1
        self.layer_3.width = 0.05
        self.layer_3.lambda_ = 0.045

        #erstelle vierte Schicht
        self.layer_4 = LayerData()
        self.layer_4.widthUnit = 1
        self.layer_4.width = 0.01
        self.layer_4.lambda_ = 0.700

        #erstelle Tab
        self.tab = TabData(0, "Test_033")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13
        self.tab.tright = 21
        self.tab.tleft = 4

        #Schichten in Tab hinzufügen
        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)
        self.tab.add_layer(self.layer_3)
        self.tab.add_layer(self.layer_4)

        self.tab.calculate()

        self.Export = Exporter(self.tab)
        self.parser = Parser(str("TestExport"))

    def test_1(self):
        """
        Export & Import
        """
        self.Export.export("TestExport")
        Tab = self.parser.parse()
        #Test der Werte im Tab
        self.assertEqual(float(self.tab.rright), float(Tab.rright))
        self.assertEqual(float(self.tab.rleft), float(Tab.rleft))
        self.assertEqual(float(self.tab.tright), float(Tab.tright))
        self.assertEqual(float(self.tab.tleft), float(Tab.tleft))

        #Test der Werte in Schicht 1
        self.assertEqual(float(Tab.layers[0].width), self.layer_1.width)
        self.assertEqual(float(Tab.layers[0].lambda_), self.layer_1.lambda_)
        self.assertEqual(float(Tab.layers[0].r), self.layer_1.r)
        self.assertEqual(float(Tab.layers[0].widthUnit), self.layer_1.widthUnit)

        #Test der Werte in Schicht 2
        self.assertEqual(float(Tab.layers[1].width), self.layer_2.width)
        self.assertEqual(float(Tab.layers[1].lambda_), self.layer_2.lambda_)
        self.assertEqual(float(Tab.layers[1].r), self.layer_2.r)
        self.assertEqual(float(Tab.layers[1].widthUnit), self.layer_2.widthUnit)

        #Test der Werte in Schicht 3
        self.assertEqual(float(Tab.layers[2].width), self.layer_3.width)
        self.assertEqual(float(Tab.layers[2].lambda_), self.layer_3.lambda_)
        self.assertEqual(float(Tab.layers[2].r), self.layer_3.r)
        self.assertEqual(float(Tab.layers[2].widthUnit), self.layer_3.widthUnit)

        #Test der Werte in Schicht 4
        self.assertEqual(float(Tab.layers[3].width), self.layer_4.width)
        self.assertEqual(float(Tab.layers[3].lambda_), self.layer_4.lambda_)
        self.assertEqual(float(Tab.layers[3].r), self.layer_4.r)
        self.assertEqual(float(Tab.layers[3].widthUnit), self.layer_4.widthUnit)
