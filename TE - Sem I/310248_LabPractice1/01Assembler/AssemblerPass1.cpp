#include <bits/stdc++.h>

using namespace std;

class Tables
{
public:
    // Language Predef
    unordered_map<string, pair<string, int>> OPTAB;
    unordered_map<string, int> REG;
    unordered_map<string, int> COND;

    // Required Output tables
    vector<pair<string, int>> SYMTAB;
    vector<pair<string, int>> LITTAB;
    vector<int> POOLTAB;

    // Initilize all the prerequired tables
    Tables()
    {
        // Imperative Statement
        OPTAB["STOP"] = {"IS", 0};
        OPTAB["ADD"] = {"IS", 1};
        OPTAB["SUB"] = {"IS", 2};
        OPTAB["MULT"] = {"IS", 3};
        OPTAB["MOVER"] = {"IS", 4};
        OPTAB["MOVEM"] = {"IS", 5};
        OPTAB["COMP"] = {"IS", 6};
        OPTAB["BC"] = {"IS", 7};
        OPTAB["DIV"] = {"IS", 9};
        OPTAB["READ"] = {"IS", 10};
        // Assembler Directives
        OPTAB["START"] = {"AD", 1};
        OPTAB["END"] = {"AD", 2};
        OPTAB["ORIGIN"] = {"AD", 3};
        OPTAB["EQU"] = {"AD", 4};
        OPTAB["LTORG"] = {"AD", 5};
        // Declaratives
        OPTAB["DC"] = {"DL", 1};
        OPTAB["DS"] = {"DL", 2};
        // Registers
        REG["AREG"] = 1;
        REG["BREG"] = 2;
        REG["CREG"] = 3;
        REG["DREG"] = 4;
        // Comprative Operators
        COND["LT"] = 1;
        COND["LE"] = 2;
        COND["EQ"] = 3;
        COND["GT"] = 4;
        COND["GE"] = 5;
        COND["ANY"] = 6;
    }

    // FUnction to Search The Symbols
    int searchSymbol(string symbol)
    {
        for (int i = 0; i < SYMTAB.size(); i++)
        {
            if (SYMTAB[i].first == symbol)
            {
                return i;
            }
        }
        return -1;
    }
    // Function get data related to Opcode
    pair<string, int> findOpcode(string str)
    {

        if (OPTAB.find(str) != OPTAB.end())
        {
            return OPTAB[str];
        }
        else
        {
            return pair<string, int>(NULL, -1);
        }
    }
};

// Implimentation of tha assembler
class AssemblerPass1
{

    Tables t;

    // Input code
    fstream inpFile;
    // Output Table files
    fstream intCode;
    fstream symTab;
    fstream litTab;
    fstream poolTab;

    // counters
    int count = 0;
    int scount = 0;
    int lcount = 0;
    int pcount = 0;

public:
    // Try Opening all the required Files:
    AssemblerPass1()
    {
        inpFile.open("input.txt", ios::in);
        if (!inpFile.is_open())
        {
            cout << "Error opennig/reading code" << endl;
        }
        intCode.open("ic.txt", ios::in);
        if (!intCode.is_open())
        {
            cout << "Error opening file" << endl;
        }
        symTab.open("stab.txt", ios::out);
        if (!symTab.is_open())
        {
            cout << "Error opening file" << endl;
        }
        litTab.open("ltab.txt", ios::out);
        if (!litTab.is_open())
        {
            cout << "Error opening file" << endl;
        }
        poolTab.open("ptab.txt", ios::out);
        if (!poolTab.is_open())
        {
            cout << "Error opening file" << endl;
        }
    }

    // Function to Process Instructio with single word
    void sizeOne(vector<string> words)
    {
        int lc = count++;

        int temp = 0;

        pair<string, int> ic;
        int temp = 0;

        if (words[0] == "LTORG")
        {

            ic = t.OPTAB[words[0]];
            intCode << lc << " "
                    << "(" << ic.first << ", " << ic.second << ")" << endl;

            t.POOLTAB.push_back(pcount + 1);
            t.LITTAB[pcount].second = lc;

            for (int i = pcount + 1; i < t.LITTAB.size(); i++)
            {

                lc = count++;
                t.LITTAB[i].second = lc;
                temp = i;
            }
            pcount = temp + 1;
        }
        else
        {
            ic = t.findOpcode(words[0]);
            intCode << lc << "(" << ic.first << ", " << ic.second << ")" << endl;
        }
    }

    // To handle instruction with two words
    void sizeTwo(vector<string> words)
    {
        int lc = count++;
        int index;
        pair<string, int> ic;
        pair<string, int> ic1;
        pair<string, int> symbol;

        if (words[0] == "ORIGIN")
        {
            ic = t.OPTAB[words[0]];
            index = t.searchSymbol(words[1]);
            count = t.SYMTAB[index].second;
            ic1.first = "S";
            ic1.second = index + 1;
        }
        else
        {
            // opcode, symbol
            ic = t.findOpcode(words[0]);
            index = t.searchSymbol(words[1]);
            ic1.first = "S";

            if (index >= 0)
            {
                ic1.second = index + 1;
            }
            else
            {
                // add entry for symbol
                scount++;
                ic1.second = scount;
                symbol.first = words[1];
                symbol.second = -1;
                t.SYMTAB.push_back(symbol);
            }
        }
        // Write to literal Table
        cout << "LC for 2 = " << lc << endl;

        intCode << lc << "(" << ic.first << ", " << ic.second << ")"
                << " "
                << "(" << ic1.first << ", " << ic1.second << ")" << endl;
    }

    void sizeThree(vector<string> words)
    {

        int lc = count++;
        pair<string, int> ic;
        pair<string, int> ic1;
        pair<string, int> ic2;

        pair<string, int> symbol;
        pair<string, int> literal;
        int index;

        ic = t.findOpcode(words[0]);

        if (t.REG.find(words[1]) != t.REG.end())
        {
            ic1.second = t.REG[words[1]];
        }

        else if (t.COND.find(words[1]) != t.COND.end())
        {
            ic1.second = t.COND[words[1]];
        }

        if (t.REG.find(words[2]) != t.REG.end())
        {
            ic2.second = t.REG[words[2]];
            intCode << lc << " "
                    << "(" << ic.first << ", " << ic.second
                    << " "
                    << "(" << ic1.second << ")"
                    << " "
                    << "(" << ic2.second << ")" << endl;
        }
        else if (words[2].at(0) == '=')
        {
            lcount++;
            ic2.first = "L";
            ic2.second = lcount;
            literal.first = words[2];
            literal.second = -1;
            t.LITTAB.push_back(literal);

            intCode << lc << " "
                    << "(" << ic.first << ", " << ic.second << ")"
                    << " "
                    << "(" << ic1.second << ")"
                    << " "
                    << "(" << ic2.first << ", " << ic2.second << ")" << endl;
        }
        else
        {
            // opcode, register, symbol
            ic2.first = "S";

            index = t.searchSymbol(words[2]);

            if (words[2] == "AGAIN")
                cout << index << endl;
            else
            {
                scount++;
                ic2.second = scount;
                symbol.first = words[2];
                symbol.second = -1;

                t.SYMTAB.push_back(symbol);
            }
            intCode << lc << " "
                    << "(" << ic.first << ", " << ic.second << ")"
                    << " "
                    << "(" << ic1.second << ")"
                    << " "
                    << "(" << ic2.first << ", " << ic2.second << ")" << endl;
        }
    }

    void passOne()
    {
        vector<string> words;
        string line;

        int index;
        int lc;
        int temp;

        pair<string, int> ic;
        pair<string, int> ic2;
        pair<string, int> ic3;

        pair<string, int> ic;
        pair<string, int> ic1;
        pair<string, int> ic2;
        pair<string, int> symbol;
        pair<string, int> literal;

        // Split evey word
        if (inpFile.is_open())
        {

            while (!inpFile.eof())
            {
                getline(inpFile, line);
                string w = "";
                for (int i = 0; i < line.size(); i++)
                {
                    if (line[i] != ' ')
                    {
                        w += line[i];
                    }
                    else
                    {
                        words.push_back(w);
                        w = "";
                    }
                }
                words.push_back(w);

                if (words[0] == "START")
                {
                    count = stoi(words[1]);
                    ic.first = "AD";
                    ic.second = 01;
                    ic1.first = "C";
                    ic1.second = stoi(words[1]);

                    intCode << " "
                            << "(" << ic.first << ", " << ic.second << ")"
                            << " "
                            << "(" << ic1.first << ", " << ic1.second << ")" << endl;
                }
                else if (words[0] == "END")
                {
                    lc = count++;
                    ic.first = "AD";
                    ic.second = 02;
                    intCode << " "
                            << "(" << ic.first << ", " << ic.second << ")" << endl;

                    t.POOLTAB.push_back(pcount + 1);
                    t.LITTAB[pcount].second = lc;

                    for (int i = pcount + 1; i < t.LITTAB.size(); i++)
                    {
                        lc = count++;
                        t.LITTAB[i].second = lc;
                    }
                    break;
                }
                else if (t.OPTAB.find(words[0]) != t.OPTAB.end())
                {
                    if (words.size() == 1)
                    {
                        this->sizeOne(words);
                    }
                    else if (words.size() == 2)
                    {
                        this->sizeTwo(words);
                    }
                    else
                    {
                        this->sizeThree(words);
                    }
                }
                else
                {
                    index = t.searchSymbol(words[0]);
                    vector<string> withoutSymbol;

                    if (index >= 0)
                    {
                        t.SYMTAB[index].second = lc + 1;
                    }
                    else
                    {
                        scount++;
                        symbol.first = words[0];
                        symbol.second = lc + 1;
                        t.SYMTAB.push_back(symbol);
                    }

                    if (words[1] == "EQU")
                    {
                        ic = t.OPTAB[words[1]];
                        lc = count++;
                        ic2.first = "S";
                        index = t.searchSymbol(words[2]);
                        ic2.second = index + 1;
                        intCode << lc << " "
                                << "(" << ic.first << ", " << ic.second << ")"
                                << " "
                                << "(" << ic1.first << ", " << ic1.second << ")" << endl;
                    }
                    else
                    {
                        this->sizeTwo(withoutSymbol);
                    }
                }
                else if (words.size() == 4)
                {
                    this->sizeThree(withoutSymbol);
                }
            }
        }
    }
};

int main()
{

    return 0;
}