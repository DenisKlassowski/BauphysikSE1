import unittest

import Calculation
from TabData import TabData
from LayerData import LayerData

class TestScript_027(unittest.TestCase):
    """
    U-Berechnung 2 Schichten
    analog manuellem TestScript_015
    """
    def setUp(self):
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 1
        self.layer_1.width = 36.5
        self.layer_1.lambda_ = 0.72

        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 1
        self.layer_2.width = 2
        self.layer_2.lambda_ = 0.87

        self.tab = TabData(0, "Test_027")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13

        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)

    def test_1(self):
        """
        Calculate R for Layer_1
        """
        self.layer_1.calculate()
        self.assertTrue(self.layer_1.r == 50.69444444444444) #warum hier das 100-fache? wann wird Einheit umgerechnet?

    def test_2(self):
        """
        Calculate R for Layer_2
        """
        self.layer_2.calculate()
        self.assertTrue(self.layer_2.r == 2.2988505747126435) #warum hier das 100-fache? wann wird Einheit umgerechnet?

    def test_3(self):
        """
        Calculate R_ges, R_T, U for Tab
        """
        self.tab.calculate()
        self.assertTrue(self.tab.rsum == 52.99329501915709)   #hier muss 0.5299 rauskommen
        self.assertTrue(self.tab.rt == 53.16329501915709)   #hier muss 0.6999 rauskommen
        self.assertTrue(self.tab.u == 0.01880997029321933) #hier muss 1.4287 rauskommen


if __name__ == '__main__':
    unittest.main()
