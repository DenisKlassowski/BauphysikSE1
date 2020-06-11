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
        self.layer_1.width = 1.0
        self.layer_1.lambda_ = 0.51

        # erstelle zweite Schicht
        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 1
        self.layer_2.width = 6.0
        self.layer_2.lambda_ = 0.04

        # erstelle dritte Schicht
        self.layer_3 = LayerData()
        self.layer_3.widthUnit = 1
        self.layer_3.width = 24.0
        self.layer_3.lambda_ = 0.79

        # erstelle vierte Schicht
        self.layer_4 = LayerData()
        self.layer_4.widthUnit = 1
        self.layer_4.width = 8.0
        self.layer_4.lambda_ = 0.04

        # erstelle fünfte Schicht
        self.layer_5 = LayerData()
        self.layer_5.widthUnit = 1
        self.layer_5.width = 1.5
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
        self.assertTrue(self.layer_1.r == 1.9607843137254901) #hier muss 0.0196 rauskommen Wo wird Einheit umgerechnet?

    def test_2(self):
        """
        Calculate R for Layer_2
        """
        self.layer_2.calculate()
        self.assertTrue(self.layer_2.r == 150.0) #hier muss 1.5000 rauskommen Wo wird Einheit umgerechnet?

    def test_3(self):
        """
        Calculate R for Layer_3
        """
        self.layer_3.calculate()
        self.assertTrue(self.layer_3.r == 30.379746835443036) #hier muss 0.3038 rauskommen Wo wird Einheit umgerechnet?

    def test_4(self):
        """
        Calculate R for Layer_4
        """
        self.layer_4.calculate()
        self.assertTrue(self.layer_4.r == 200.0) #hier muss 2.0000 rauskommen Wo wird Einheit umgerechnet?

    def test_5(self):
        """
        Calculate R for Layer_5
        """
        self.layer_5.calculate()
        self.assertTrue(self.layer_5.r == 2.142857142857143) #hier muss 0.0214 rauskommen Wo wird Einheit umgerechnet?

    def test_6(self):
        """
        Calculate R_ges, R_T, U for Tab
        """
        self.tab.calculate()
        self.assertTrue(self.tab.rsum == 384.4833882920257)   #hier muss 3.8448 rauskommen
        self.assertTrue(self.tab.rt == 384.65338829202574)   #hier muss 4.0148 rauskommen
        self.assertTrue(self.tab.u == 0.0025997431205280535) #hier muss 0.2491 rauskommen


if __name__ == '__main__':
    unittest.main()
