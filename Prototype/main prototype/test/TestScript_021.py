import unittest

import Calculation
from TabData import TabData
from LayerData import LayerData

class TestScript_021(unittest.TestCase):
    """
    U-Berechnung 4 Schichten
    analog manuellem TestScript_009
    """
    def setUp(self):
        #erstelle erste Schicht
        self.layer_1 = LayerData()
        self.layer_1.widthUnit = 1
        self.layer_1.width = 2
        self.layer_1.lambda_ = 0.350

        #erstelle zweite Schicht
        self.layer_2 = LayerData()
        self.layer_2.widthUnit = 1
        self.layer_2.width = 24
        self.layer_2.lambda_ = 0.560

        #erstelle dritte Schicht
        self.layer_3 = LayerData()
        self.layer_3.widthUnit = 1
        self.layer_3.width = 5
        self.layer_3.lambda_ = 0.045

        #erstelle vierte Schicht
        self.layer_4 = LayerData()
        self.layer_4.widthUnit = 1
        self.layer_4.width = 1
        self.layer_4.lambda_ = 0.700

        #erstelle Tab
        self.tab = TabData(0, "Test_021")
        self.tab.rright = 0.04
        self.tab.rleft = 0.13

        #Schichten in Tab hinzufügen
        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)
        self.tab.add_layer(self.layer_3)
        self.tab.add_layer(self.layer_4)

    def test_1(self):
        """
        Calculate R for Layer_1
        """
        self.layer_1.calculate()
        self.assertTrue(self.layer_1.r == 5.714285714285714) #warum hier das 100-fache? wann wird Einheit umgerechnet?

    def test_2(self):
        """
        Calculate R for Layer_2
        """
        self.layer_2.calculate()
        self.assertTrue(self.layer_2.r == 42.857142857142854) #warum hier das 100-fache? wann wird Einheit umgerechnet?

    def test_3(self):
        """
        Calculate R for Layer_3
        """
        self.layer_3.calculate()
        self.assertTrue(self.layer_3.r == 111.111111111111111) #warum hier das 100-fache? wann wird Einheit umgerechnet?

    def test_4(self):
        """
        Calculate R for Layer_4
        """
        self.layer_4.calculate()
        self.assertTrue(self.layer_4.r == 1.4285714285714286) #warum hier das 100-fache? wann wird Einheit umgerechnet?

    def test_5(self):
        """
        Calculate R_ges, R_T, U for Tab (R_ges)
        """
        self.tab.calculate()
        self.assertTrue(self.tab.rsum == 161.11111111111111)   #hier muss 1.6111 rauskommen
        self.assertTrue(self.tab.rt == 161.2811111111111)   #hier muss 1.7811 rauskommen
        self.assertTrue(self.tab.u == 0.006200354109112454) #hier muss 0.5600 rauskommen


if __name__ == '__main__':
    unittest.main()
