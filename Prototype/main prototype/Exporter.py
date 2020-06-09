class Exporter:
    def __init__(self, tab):
        self.tab = tab

    def export(self, filename):
        data = ""
        data += "name: " + self.tab.name + "\n"
        data += "rright: " + self.tab.rright + "\n"
        data += "rleft: " + self.tab.rleft + "\n"
        data += "rsum: " + self.tab.rsum + "\n"
        data += "tright: " + self.tab.tright + "\n"
        data += "tleft: " + self.tab.tleft + "\n"
        data += "mode: " + self.tab.mode + "\n"
        data += "u: " + self.tab.u + "\n"
        data += "rt: " + self.tab.rt + "\n"

        layers = "layers:\n"

        for layer in self.tab.layers:
            layers += "\tlayer: "
            layers += layer.width + ", "
            layers += layer.widthUnit + ", "
            layers += layer.lambda_ + ", "
            layers += layer.r + ", "
            layers += layer.t_left + ", "
            layers += layer.t_right + ", "
            layers += layer.rho + ", "
            layers += layer.mat + "\n"

        full_string = data + layers
        f = open(filename + ".baup", "w")
        f.write(full_string)
