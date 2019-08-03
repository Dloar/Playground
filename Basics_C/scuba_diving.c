/* scuba diving function." */
#define consumption 30

main(){
    int deep, time, bottle_presure, reserve, req_air, deep_consumption, consumption;
    float bottle_volume = 0.0, presure_atm = 0.0;
    printf("Please input for how long you want to be under the watter[minutes].");
    scanf("%d", &time);
    printf("Please insert how deep you want to dive[meters].");
    scanf("%d", &deep);
    printf("Please insert pressure of the bottle.");
    scanf("%d", &bottle_presure);
    printf("Please insert reserve you want to remain.");
    scanf("%d", &reserve);

printf("\nFor %d minutes dive into %d metres.", time, deep);
    presure_atm = 1 + ((double)deep/(double)10);
    deep_consumption = consumption * presure_atm;
    req_air = time * deep_consumption;
        bottle_volume = req_air/(bottle_presure-reserve);

printf("\nYou need %.1f liters of oxygen.\n", bottle_volume);
}
