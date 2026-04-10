#include <cmath>

struct Input {
    float signal_primary;
    float signal_secondary;
    float context_load;
    bool has_context_load;
};

struct Output {
    float anomaly_score;
    bool anomaly_flag;
};

static float clamp01(float value) {
    if (value < 0.0f) return 0.0f;
    if (value > 1.0f) return 1.0f;
    return value;
}

Output run_model(const Input& in) {
    const float nominal_context = 0.5f;
    const float context = in.has_context_load ? in.context_load : nominal_context;

    float delta = std::fabs(in.signal_primary - in.signal_secondary);
    float score = clamp01((delta * 0.8f) + (std::fabs(context - 0.5f) * 0.2f));

    Output out;
    out.anomaly_score = score;
    out.anomaly_flag = (score > 0.65f);
    return out;
}
