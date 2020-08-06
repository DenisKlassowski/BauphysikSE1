import unittest

import Calculation
from TabData import TabData
from LayerData import LayerData

class TestScript_029(unittest.TestCase):
    """
    Temperaturverlaufs-Berechnung 2 Schichten
    analog manuellem TestScript_017
    """
    def setUp(self):
        self.layer_1 = LayerData()
        self.layer_1.r = 0.25

        self.layer_2 = LayerData()
        self.layer_2.r = 2.86

        self.tab = TabData(1, "Test_029")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13
        self.tab.tright = -7.5
        self.tab.tleft = 20

        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)

        self.tab.calculate()

    def test_1(self):
        """
        Calculate R_ges, R_T, U for Tab
        """
        self.assertTrue(self.tab.rsum == 3.11)
        self.assertTrue(self.tab.rt == 3.28)
        self.assertTrue(round(self.tab.u,4) == 0.3049)

    def test_2(self):
        """
            Check calculated temperature
        """
        self.assertEqual(round(self.tab.layers[0].t_left, 2), 18.91)
        self.assertEqual(round(self.tab.layers[0].t_right, 2), 16.81)
        self.assertEqual(round(self.tab.layers[1].t_left, 2), 16.81)
        self.assertEqual(round(self.tab.layers[1].t_right, 2), -7.16)


if __name__ == '__main__':
    unittest.main()
