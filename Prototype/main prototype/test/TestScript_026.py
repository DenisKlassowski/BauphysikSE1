import unittest

import Calculation
from TabData import TabData
from LayerData import LayerData

class TestScript_021(unittest.TestCase):
    """
    U-Berechnung 2 Schichten
    analog manuellem TestScript_014
    """
    def setUp(self):
        #erstelle erste Schicht
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 1
        self.layer_1.width = 0.2
        self.layer_1.lambda_ = 2.5

        #erstelle zweite Schicht
        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 1
        self.layer_2.width = 0.05
        self.layer_2.lambda_ = 0.035

        #erstelle Tab
        self.tab = TabData(0, "Test_021")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13

        #Schichten in Tab hinzufügen
        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)

    def test_1(self):
        """
        Calculate R for Layer_1
        """
        self.layer_1.calculate()
        self.assertTrue(round(self.layer_1.r,5) == 0.08000)

    def test_2(self):
        """
        Calculate R for Layer_2
        """
        self.layer_2.calculate()
        self.assertTrue(round(self.layer_2.r,5) == 1.42857)

    def test_5(self):
        """
        Calculate R_ges, R_T, U for Tab (R_ges)
        """
        self.tab.calculate()
        self.assertTrue(round(self.tab.rsum,4) == 1.5086)
        self.assertTrue(round(self.tab.rt,4) == 1.6786)
        self.assertTrue(round(self.tab.u,4) == 0.5957)


if __name__ == '__main__':
    unittest.main()
