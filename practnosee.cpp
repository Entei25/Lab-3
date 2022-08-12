

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <sstream>
using namespace std;

void f_met(vector <string>& v)
{
    string a = "";
    vector <string> aux;
    int ceros = 0, unos = 0;

    for (int i = 0; i < v[0].size(); ++i)
    {
        if (v[0][i] == '1')
        {
            ceros += 1;
            a += '0';
        }
        else if (v[0][i] == '0')
        {
            unos += 1;
            a += '1';
        }
    }
    aux.push_back(a);
    for (int k = 1; k < v.size(); ++k)
    {
        if (ceros > unos)
        {
            a = "";
            ceros = 0, unos = 0;
            int count = 0;
            for (int j = 0; j < v[k].size(); ++j)
            {
                ++count;
                if (count != 2)
                {
                    a += v[k][j];
                    if (v[k][j] == '1')
                    {
                        ++unos;
                    }
                    else if (v[k][j] == '0')
                    {
                        ++ceros;
                    }

                }
                else
                {
                    count = 0;
                    if (v[k][j] == '1')
                    {
                        ++unos;
                        a += '0';
                    }
                    else if (v[k][j] == '0')
                    {
                        ++ceros;
                        a += '1';
                    }
                }


            }
            aux.push_back(a);
        }
        else if (ceros < unos)
        {
            a = "";
            ceros = 0, unos = 0;
            int count = 0;
            for (int j = 0; j < v[k].size(); ++j)
            {
                ++count;
                if (count != 2)
                {
                    a += v[k][j];
                    if (v[k][j] == '1')
                    {
                        ++unos;
                    }
                    else if (v[k][j] == '0')
                    {
                        ++ceros;
                    }

                }
                else
                {
                    count = 0;
                    if (v[k][j] == '1')
                    {
                        ++unos;
                        a += '0';
                    }
                    else if (v[k][j] == '0')
                    {
                        ++ceros;
                        a += '1';
                    }
                }


            }
            aux.push_back(a);
        }
        else if (ceros == unos)
        {
            a = "";
            ceros = 0, unos = 0;
            int count;
            for (int j = 0; j < v[k].size(); ++j)
            {
                if (v[k][j] == '1')
                {
                    ceros += 1;
                    a += '0';
                }
                else if (v[k][j] == '0')
                {
                    unos += 1;
                    a += '1';
                }
            }
            aux.push_back(a);
        }
    }
    v = aux;

}





void s_met(vector <string>& v) 
{
    string a = "";
    vector <string> b;
    int count = 0;
    int n = v[0].size();
    for (int i = 0; i < v.size(); ++i)
    {
        char aux = v[i].back();
        string n_bin = "";
        n_bin += aux;
        n_bin += v[i];
        n_bin.pop_back();
        b.push_back(n_bin);
        n_bin = "";
    }
    v = b;
}


void des_s_met(vector <string>& v)
{
    string a = "";
    vector <string> b;
    int count = 0;
    int n = v[0].size();
    for (int i = 0; i < v.size(); ++i)
    {
        char aux = v[i].front();
        v[i].erase(v[i].begin());
        b.push_back(v[i] + aux);
    }
    v = b;
}




string str_to_bin(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString += bitset<8>(_char).to_string();
    }
    return binaryString;
}


string bin_to_str(string data) {
    stringstream sstream(data);
    string output;
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    return output;
}




vector <string> separate(string k, int n)
{
    vector <string> v;
    int count  = 0;
    string  a = "";
    for (int i = 0; i < k.length(); ++i)
    {
        count++;
        if (i == k.length() - (k.length() % n))
        {
            for (int j = 0; j < (n - (k.length() % n)); ++j)
            {
                a += "0";
                count++;

            }
            a += k[i];
        }
        else
        {
            a += k[i];
        }
        if (count == n)
        {
            v.push_back(a);
            count = 0;
            a = "";
        }
    }
    return v;
}


int main()
{
    string v = "AbCd";
    string a = str_to_bin(v);
    vector <string> b = separate(a,4);
    vector <string> c = separate(a, 4);
    f_met(b);
    s_met(c);
    //s_met(b);
    //des_s_met(b);
    cout << "Ejemplo Si se ingresa 4 y el archivo contiene AbCd." << endl;
    cout << "el binario sin codificar es 01000001011000100100001101100100" << endl;
    cout << "el binari codificado por el primer metodo es " << endl;
    for (int i = 0; i < b.size(); ++i) 
    {
        cout << b[i];
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Ejemplo Si se ingresa 4 y el archivo contiene AbCd." << endl;
    cout << "el binario sin codificar es 01000001011000100100001101100100" << endl;
    cout << "el binari codificado por el segundo metodo es " << endl;
    for (int i = 0; i < c.size(); ++i)
    {
        cout << c[i];
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "y estos decoficados con " << endl;
    cout << "primer metodo:" << endl;
    f_met(b);
    for (int i = 0; i < b.size(); ++i)
    {
        cout << b[i];
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "segundo metodo:" << endl;
    des_s_met(c);
    for (int i = 0; i < c.size(); ++i)
    {
        cout << c[i];
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "y por ultimo los decoficicamos a str otra vez" << endl;
    cout << bin_to_str(a) << endl;
}
