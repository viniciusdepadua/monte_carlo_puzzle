#include <iostream>
#include <bits/stdc++.h>
#include <random>
#include <algorithm>
#include "time.h"

using namespace std;

// you can also create this as a static variable inside randomFloat()

random_device rd;
default_random_engine generator(rd()); // rd() provides a random seed
uniform_real_distribution<float> distribution(0.000000,1.000000);

float randomFloat() {

    float x = distribution(generator);
    return x;
}


unsigned long long simulationA(unsigned long long persons){
    unsigned long long time = 0;
    bool finished = false;
    unsigned long long kombucha_place = 0;
    vector <bool> circle (persons,false);
    bool flag_direction = true;
    while(!finished){
        float p_right = float (kombucha_place+1) / float (persons+1);
        float p_left = float (persons - kombucha_place) / float (persons+1);
        if(circle[kombucha_place]){
            if(kombucha_place == 0 && flag_direction == 0){
                kombucha_place = persons - 1;
            }
            else {
                kombucha_place = kombucha_place + (-1 * (!flag_direction) + flag_direction);
                kombucha_place = kombucha_place % persons;
            }
        }
        else{
            circle[kombucha_place] = true;
            float rnd_flag = randomFloat();
            if(p_right >= p_left){
                if(rnd_flag <= p_left){
                    flag_direction = false;
                }
                else{
                    flag_direction = true;
                }
            }
            else{
                if(rnd_flag <= p_right){
                    flag_direction = true;
                }
                else{
                    flag_direction = false;
                }
            }
            if(kombucha_place == 0 && flag_direction == 0){
                kombucha_place = persons - 1;
            }
            else {
                kombucha_place = kombucha_place + (-1 * (!flag_direction) + flag_direction);
                kombucha_place = kombucha_place % persons;
            }
        }
        time = time + 1;
        if(all_of(begin(circle), end(circle),[](bool i){return i;})){
            finished = true;
        }
    }
    return time;
}

unsigned long long simulationB(unsigned long long persons){
    unsigned long long time = 0;
    bool finished = false;
    unsigned long long kombucha_place = 0;
    vector <bool> circle (persons,false);
    bool flag_direction = true;
    while(!finished){
        float p_right = float (kombucha_place+1) / float (persons+1);
        float p_left = float (persons - kombucha_place) / float (persons+1);
        circle[kombucha_place] = true;
        float rnd_flag = randomFloat();
        if(p_right >= p_left){
            if(rnd_flag <= p_left){
                flag_direction = false;
            }
            else{
                flag_direction = true;
            }
        }
        else{
            if(rnd_flag <= p_right){
                flag_direction = true;
            }
            else{
                flag_direction = false;
            }
        }
        if(kombucha_place == 0 && flag_direction == 0){
            kombucha_place = persons - 1;
        }
        else {
            kombucha_place = kombucha_place + (-1 * (!flag_direction) + flag_direction);
            kombucha_place = kombucha_place % persons;
        }
        time = time + 1;
        if(all_of(begin(circle), end(circle),[](bool i){return i;})){
            finished = true;
        }
    }
    return time;
}

double monte_carloB(unsigned long long samples, unsigned long long persons){
    unsigned long long sum = 0;
    for(unsigned long long i = 0; i < samples; i++) {
        sum = sum + simulationB(persons);
    }
    double time = static_cast<double> (sum) / static_cast<double >(samples);
    return time;
}

double monte_carloA(unsigned long long samples, unsigned long long persons){
    unsigned long long sum = 0;
    for(unsigned long long i = 0; i < samples; i++) {
        sum = sum + simulationA(persons);
    }
    double time = static_cast<double> (sum) / static_cast<double >(samples);
    return time;
}

int main() {
    clock_t start = clock();
    double timeA30 = monte_carloA(10,30);
    double timeA500 = monte_carloA(10,500);
    double timeB10 = monte_carloB(10,10);
    double timeB30 = monte_carloB(10,30);
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execução é: " << setprecision(7) << time_taken << " s " << endl;
    cout << fixed << setprecision(8) <<"Tempo esperado para letra A com N = 30: " << timeA30 <<endl;
    cout << fixed << setprecision(8) <<"Tempo esperado para letra A com N = 30: " << timeA500 <<endl;
    cout << fixed << setprecision(8) <<"Tempo esperado para letra A com N = 30: " << timeB10 <<endl;
    cout << fixed << setprecision(8) <<"Tempo esperado para letra A com N = 30: " << timeB30 <<endl;
    return 0;
}
