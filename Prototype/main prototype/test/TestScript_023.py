import unittest

import Calculation
from TabData import TabData
from LayerData import LayerData

class TestScript_023(unittest.TestCase):
    """
    U-Berechnung 5 Schichten
    analog manuellem TestScript_011
    """

    def setUp(self):
        # erstelle erste Schicht
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 1
        self.layer_1.width = 0.01
        self.layer_1.lambda_ = 0.51

        # erstelle zweite Schicht
        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 1
        self.layer_2.width = 0.06
        self.layer_2.lambda_ = 0.04

        # erstelle dritte Schicht
        self.layer_3 = LayerData()
        self.layer_3.widthUnit = 1
        self.layer_3.width = 0.24
        self.layer_3.lambda_ = 0.79

        # erstelle vierte Schicht
        self.layer_4 = LayerData()
        self.layer_4.widthUnit = 1
        self.layer_4.width = 0.08
        self.layer_4.lambda_ = 0.04

        # erstelle fünfte Schicht
        self.layer_5 = LayerData()
        self.layer_5.widthUnit = 1
        self.layer_5.width = 0.015
        self.layer_5.lambda_ = 0.70

        # erstelle Tab
        self.tab = TabData(0, "Test_023")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13

        # Schichten in Tab hinzufügen
        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)
        self.tab.add_layer(self.layer_3)
        self.tab.add_layer(self.layer_4)
        self.tab.add_layer(self.layer_5)

    def test_1(self):
        """
        Calculate R for Layer_1
        """
        self.layer_1.calculate()
        self.assertTrue(round(self.layer_1.r,5) == 0.01961)

    def test_2(self):
        """
        Calculate R for Layer_2
        """
        self.layer_2.calculate()
        self.assertTrue(round(self.layer_2.r,5) == 1.50000)

    def test_3(self):
        """
        Calculate R for Layer_3
        """
        self.layer_3.calculate()
        self.assertTrue(round(self.layer_3.r,5) == 0.30380)

    def test_4(self):
        """
        Calculate R for Layer_4
        """
        self.layer_4.calculate()
        self.assertTrue(round(self.layer_4.r,5) == 2.00000)

    def test_5(self):
        """
        Calculate R for Layer_5
        """
        self.layer_5.calculate()
        self.assertTrue(round(self.layer_5.r,5) == 0.02143)

    def test_6(self):
        """
        Calculate R_ges, R_T, U for Tab
        """
        self.tab.calculate()
        self.assertTrue(round(self.tab.rsum,4) == 3.8448)
        self.assertTrue(round(self.tab.rt,4) == 4.0148)
        self.assertTrue(round(self.tab.u,4) == 0.2491)


if __name__ == '__main__':
    unittest.main()
