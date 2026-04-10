#include <cmath>

struct Input {
    float current_value;
    float trend_value;
    bool has_trend_value;
};

struct Output {
    float predicted_value;
};

static float clamp01(float value) {
    if (value < 0.0f) return 0.0f;
    if (value > 1.0f) return 1.0f;
    return value;
}

Output run_model(const Input& in) {
    float trend = in.has_trend_value ? in.trend_value : 0.0f;

    Output out;
    out.predicted_value = clamp01(in.current_value + (trend * 0.1f));
    return out;
}
