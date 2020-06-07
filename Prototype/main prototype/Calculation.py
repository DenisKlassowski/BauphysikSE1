def layer_calc(l):
    calc_r(l)


def tab_calc(t):
    if t.mode == 0:  # u calculation
        full_u_calc(t)
    elif t.mode == 1:  # temp calculation
        # if t.u == 0.0:
        # full_u_calc(t)
        full_u_calc(t)

        j = t.u * (t.tright - t.tleft)
        rho_right = t.rright * j
        rho_left = t.rleft * j

        for i in range(len(t.layers)):
            t.layers[i].rho = t.layers[i].r * j

            """
            if t.tleft < t.tright:
                if i == 0:
                    t.layers[i].t_inside = t.tright - rho_inside
                else:
                    t.layers[i].t_inside = t.layers[i - 1].t_outside

                t.layers[i].t_outside = t.layers[i].t_inside - t.layers[i].rho
            elif t.tleft > t.tright:
                if i == 0:
                    t.layers[i].t_inside = t.tright + rho_inside
                else:
                    t.layers[i].t_inside = t.layers[i - 1].t_outside

                t.layers[i].t_outside = t.layers[i].t_inside + t.layers[i].rho
            else:
                t.layers[i].t_inside = t.tleft
                t.layers[i].t_outside = t.tleft
            """
            if i == 0:
                t.layers[i].t_left = t.tleft + rho_left
            else:
                t.layers[i].t_left = t.layers[i - 1].t_right

            t.layers[i].t_right = t.layers[i].t_left + t.layers[i].rho

    # elif t.mode == 3:  # ....


def full_u_calc(t):
    r = calc_all_r(t.layers)
    rt = calc_rt(t.rright, t.rleft, r)
    u = calc_u(rt)
    t.rsum = r
    t.u = u
    t.rt = rt


def calc_rt(rright, rleft, r):
    return rright + rleft + r


def calc_u(rt):
    try:
        return 1 / rt
    except ZeroDivisionError:
        raise ZeroDivisionError


def calc_all_r(layers):
    r = 0
    for layer in layers:
        if layer.r == 0.0:
            r += calc_r(layer)
        else:
            r += layer.r
    return r


def calc_r(layer):
    try:
        layer.r = layer.width / layer.lambda_
        return layer.r
    except ZeroDivisionError:
        raise ZeroDivisionError

def calc_lambda(layer):
    try:
        layer.lambda_ = layer.width/layer.r
        return layer.lambda_
    except ZeroDivisionError:
        raise ZeroDivisionError
