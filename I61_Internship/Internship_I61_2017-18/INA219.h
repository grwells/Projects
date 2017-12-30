class INA219
{
  private:
    int fd;
    float current_mA;
    float voltage_mV;

  public:
    bool setup();
    bool setup(int ina_addr);
    float getCurrent();
    float getVoltage();
};
