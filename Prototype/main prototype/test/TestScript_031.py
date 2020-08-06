import unittest

import Calculation
from TabData import TabData
from LayerData import LayerData

class TestScript_031(unittest.TestCase):
    """
    Temperaturverlaufs-Berechnung 2 Schichten
    analog manuellem TestScript_019
    """
    def setUp(self):
        self.layer_1 = LayerData()
        self.layer_1.r = 2.5

        self.layer_2 = LayerData()
        self.layer_2.r = 0.54

        self.tab = TabData(1, "Test_031")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13
        self.tab.tright = 26
        self.tab.tleft = 21

        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)

    def test_3(self):
        """
        Calculate R_ges, R_T, U for Tab
        """
        self.tab.calculate()
        self.assertTrue(self.tab.rsum == 3.04)
        self.assertTrue(self.tab.rt == 3.21)
        self.assertTrue(round(self.tab.u, 4) == 0.3115)

    def test_4(self):
        """
            Check calculated temperature
        """
        self.tab.calculate()
        self.assertTrue(round(self.tab.layers[0].t_left, 2) == 21.20)
        self.assertTrue(round(self.tab.layers[0].t_right, 2) == 25.10)
        self.assertTrue(round(self.tab.layers[1].t_left, 2) == 25.10)
        self.assertTrue(round(self.tab.layers[1].t_right, 2) == 25.94)


if __name__ == '__main__':
    unittest.main()
