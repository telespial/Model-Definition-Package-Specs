#include <cmath>

struct Input {
    float pos_x;
    float pos_y;
    float vel_x;
    bool has_velocity;
};

struct Output {
    float aim_x;
};

Output run_model(const Input& in) {
    Output out;

    if (in.has_velocity) {
        out.aim_x = in.pos_x + (in.vel_x * 0.1f);
    } else {
        out.aim_x = in.pos_x;
    }

    return out;
}
