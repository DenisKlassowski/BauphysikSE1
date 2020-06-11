import unittest

from TabData import TabData
from LayerData import LayerData

class TestScript_022(unittest.TestCase):
    """
    U-Berechnung 3 Schichten
    analog manuellem TestScript_010
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

        self.tab = TabData(0, "Test_022")
        self.tab.add_layer(self.layer_1)
        self.tab.add_layer(self.layer_2)
        self.tab.add_layer(self.layer_3)

    def test_1(self):
        """
        Calculate R for Layer_1
        """
        self.layer_1.calculate()
        self.assertTrue(self.layer_1.r == 0.4861111111111111) #Runden auf 4 Nachkommastellen sinnvoll

    def test_2(self):
        """
        Calculate R for Layer_2
        """
        self.layer_2.calculate()
        self.assertTrue(self.layer_2.r == 5.000) #Runden auf 4 Nachkommastellen sinnvoll

    def test_3(self):
        """
        Calculate R for Layer_3
        """
        self.layer_3.calculate()
        self.assertTrue(self.layer_3.r == 0.09583333333333334) #Runden auf 4 Nachkommastellen sinnvoll

    def test_4(self):
        """
        Calculate R_ges, R_T, U for Tab (R_ges)
        """
        self.tab.calculate()
        self.assertTrue(self.tab.rsum == 5.581944444444444)   #hier muss 1.6111 rauskommen
        self.assertTrue(self.tab.rt == 5.581944444444444)   #hier muss 1.7811 rauskommen
        self.assertTrue(self.tab.u == 0.17914904205026128) #hier muss 0.5600 rauskommen


if __name__ == '__main__':
    unittest.main()
