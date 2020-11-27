

class Brazo{
    public:
        Brazo();
        float L1;
        float L2;
        float L3;
        std::tuple <float, float, float> pos_motores(std::tuple <float, float, float> pos_obj);
    private:
};