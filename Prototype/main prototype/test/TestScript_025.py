import unittest

import Calculation
from TabData import TabData
from LayerData import LayerData

class TestScript_025(unittest.TestCase):
    """
    U-Berechnung 2 Schichten
    analog manuellem TestScript_013
    """
    def setUp(self):
        self.layer_1 = LayerData()
        self.layer_1.r = 0.54

        self.layer_2 = LayerData()
        self.layer_2.r = 2.5

        self.tab = TabData(0, "Test_025")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13

        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)

    def test_3(self):
        """
        Calculate R_ges, R_T, U for Tab
        """
        self.tab.calculate()
        self.assertTrue(self.tab.rsum == 3.04)
        self.assertTrue(self.tab.rt == 3.21)
        self.assertTrue(round(self.tab.u,4) == 0.3115)


if __name__ == '__main__':
    unittest.main()
