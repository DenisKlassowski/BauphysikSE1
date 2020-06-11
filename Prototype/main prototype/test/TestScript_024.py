import unittest

import Calculation
from TabData import TabData
from LayerData import LayerData

class TestScript_027(unittest.TestCase):
    """
    U-Berechnung 2 Schichten
    analog manuellem TestScript_012
    """
    def setUp(self):
        self.layer_1 = LayerData()
        self.layer_1.r = 0.25

        self.layer_2 = LayerData()
        self.layer_2.r = 2.86

        self.tab = TabData(0, "Test_024")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13

        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)

    def test_3(self):
        """
        Calculate R_ges, R_T, U for Tab
        """
        self.tab.calculate()
        self.assertTrue(self.tab.rsum == 3.11)
        self.assertTrue(self.tab.rt == 3.28)
        self.assertTrue(self.tab.u == 0.3048780487804878) #hier muss 0.3049 rauskommen


if __name__ == '__main__':
    unittest.main()
