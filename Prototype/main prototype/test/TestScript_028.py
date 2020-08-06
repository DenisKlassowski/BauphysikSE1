import unittest

from TabData import TabData
from LayerData import LayerData

class TestScript_028(unittest.TestCase):
    """
    Temperaturverlaufs-Berechnung 3 Schichten
    analog manuellem TestScript_016
    """
    def setUp(self):
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 0
        self.layer_1.width = 0.175
        self.layer_1.lambda_ = 0.36

        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 0
        self.layer_2.width = 0.150
        self.layer_2.lambda_ = 0.03

        self.layer_3 = LayerData()
        self.layer_3.widthUnit = 0
        self.layer_3.width = 0.115
        self.layer_3.lambda_ = 1.20

        self.tab = TabData(1, "Test_028")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13
        self.tab.tright = -4
        self.tab.tleft = 19

        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)
        self.tab.add_layer(self.layer_3)

        self.tab.calculate()

    def test_1(self):
        """
        Calculate R for Layer_1
        """
        self.layer_1.calculate()
        self.assertTrue(round(self.layer_1.r, 5) == 0.48611)

    def test_2(self):
        """
        Calculate R for Layer_2
        """
        self.layer_2.calculate()
        self.assertTrue(round(self.layer_2.r, 5) == 5.0000)

    def test_3(self):
        """
        Calculate R for Layer_3
        """
        self.layer_3.calculate()
        self.assertTrue(round(self.layer_3.r, 5) == 0.09583)

    def test_4(self):
        """
        Calculate R_ges, R_T, U for Tab (R_ges)
        """
        self.assertTrue(round(self.tab.rsum, 4) == 5.5819)
        self.assertTrue(round(self.tab.rt, 4) == 5.7519)
        self.assertTrue(round(self.tab.u, 4) == 0.1739)

    def test_5(self):
        """
        Check calculated temperature
        """
        self.assertEqual(round(self.tab.layers[0].t_left, 2), 18.48)
        self.assertEqual(round(self.tab.layers[0].t_right, 2), 16.54)
        self.assertEqual(round(self.tab.layers[1].t_left, 2), 16.54)
        self.assertEqual(round(self.tab.layers[1].t_right, 2), -3.46)
        self.assertEqual(round(self.tab.layers[2].t_left, 2), -3.46)
        self.assertEqual(round(self.tab.layers[2].t_right, 2), -3.84)


if __name__ == '__main__':
    unittest.main()
