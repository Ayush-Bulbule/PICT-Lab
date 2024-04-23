#include <bits/stdc++.h>
using namespace std;

class macro
{

    vector<tuple<string, int, int, int, int>> MNTAB; // name #PP #KP #KDTP # MDTP
    vector<tuple<string, string>> KDTAB;             // keyword_name value
    vector<vector<string>> MDT;                      // operation opcode1 opcode2
    vector<vector<tuple<string, string>>> APTAB;     // 2D mat with each element as para and value
    vector<vector<string>> PNTAB;                    // 2D mat with just para
    vector<vector<string>> myToken;                  // 2d mat ---->each row is a line from input
    ifstream ipFile;

public:
    macro()
    {
        ipFile.open("macro_input_2.txt", ios::in);
        string buffer;
        string words;
        while (!ipFile.eof())
        {
            vector<string> token;
            getline(ipFile, buffer);
            stringstream ss(buffer);
            while (ss >> words)
            {
                if (words != ",")
                    token.push_back(words);
            }
            myToken.push_back(token);
        }
        displayToken();
    }
    void displayToken()
    {
        for (int i = 0; i < myToken.size(); i++)
        {
            cout << i << " :";
            for (int j = 0; j < myToken[i].size(); j++)
            {
                cout << myToken[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void displayAll()
    {
        // MNT
        cout << "\n---------MNT-----------\n";
        cout << "Name\t#PP\t#KP\t#MDTP\t#KDTP\n";
        for (int i = 0; i < MNTAB.size(); i++)
        {
            string name = get<0>(MNTAB[i]); // First element is a string
            int PP = get<1>(MNTAB[i]);
            int KP = get<2>(MNTAB[i]);
            int MDTP = get<3>(MNTAB[i]);
            int KDTP = get<4>(MNTAB[i]);

            std::cout << name << "\t" << PP << "\t" << KP << "\t" << MDTP << "\t" << KDTP << "\n";
        }
        cout << "-------------------------\n";

        // MDT
        cout << "\n---------MDT-----------\n";
        for (int i = 0; i < MDT.size(); i++)
        {
            for (int j = 0; j < MDT[i].size(); j++)
            {
                cout << MDT[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "-------------------------\n";

        // KDTAB
        cout << "\n--------KDTAB----------\n";
        cout << "Keyword\tValue\n";
        for (int i = 0; i < KDTAB.size(); i++)
        {
            string keyword = get<0>(KDTAB[i]);
            string value = get<1>(KDTAB[i]);
            cout << keyword << "\t" << value << endl;
            ;
        }
        cout << "-------------------------\n";

        // PNTAB
        cout << "\n--------PNTAB----------\n";
        for (int i = 0; i < PNTAB.size(); i++)
        {
            for (int j = 0; j < PNTAB[i].size(); j++)
            {
                cout << PNTAB[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "-----------------------\n";
    }
    void displayAPTAB(string macroName, vector<string> &APTAB)
    {
        cout << "\n--------APTAB[" << macroName << "]------------\n";
        for (int k = 0; k < APTAB.size(); k++)
        {
            cout << k << " :" << APTAB[k] << endl;
        }
        cout << "\n-------------------------------------------\n";
    }
    int deal(string token, int index)
    {
        // searches in PNTab of curr macro
        for (int i = 0; i < PNTAB[index].size(); i++)
        {
            if (PNTAB[index][i] == token)
                return i + 1;
        }
        return -1;
    }
    int findInMNT(string name)
    {
        string temp;
        for (int i = 0; i < MNTAB.size(); i++)
        {
            if (name == get<0>(MNTAB[i]))
                return i;
        }
        return -1; //(return false)
    }
    string getValueFromKDTAB(string key, int KDTP)
    {
        for (int i = KDTP; i < KDTAB.size(); i++)
        {
            if (get<0>(KDTAB[i]) == key)
                return get<1>(KDTAB[i]);
        }
        return "Not today";
    }
    int getKeywordIndex(string keyword, int macroIndex)
    {
        vector<string> currparameters = PNTAB[macroIndex];
        for (int i = 0; i < currparameters.size(); i++)
        {
            if (currparameters[i] == keyword)
                return i;
        }
        return -1;
    }
    int getMacroLength(string macName)
    {

        int index = findInMNT(macName);
        //    cout<<"index :"<<index<<endl;
        //    cout<<"MDTP"<<get<3>(MNTAB[index])<<endl;
        for (int k = get<3>(MNTAB[index]);; k++)
        {
            // cout<<MDT[k][0]<<endl;
            if (MDT[k][0] == "MEND")
            {
                // cout<<"-->";
                return k + 1 - get<3>(MNTAB[index]);
            }
        }
    }
    int storeDefination(int lineNum)
    {
        string name;
        vector<string> tempPNTAB;
        int PP, KP, KDTP, MDTP, j;
        KP = PP = 0;

        MDTP = MDT.size();
        KDTP = KDTAB.size();
        // first line(name,parameters)
        name = myToken[lineNum][0];
        for (int i = 1; i < myToken[lineNum].size(); i++)
        {
            string currToken = myToken[lineNum][i];

            if (currToken.find("=") != string::npos)
            {
                // keyword parameter
                KP++;
                auto index = currToken.find("=");
                string value = currToken.substr(index + 1, currToken.length() - index);
                string keyword = currToken.substr(0, index);
                // cout<<"K : "<<keyword<<" - "<<value<<endl;
                tuple<string, string> t1(keyword, value);
                KDTAB.push_back(t1);
                tempPNTAB.push_back(keyword);
            }
            else
            {
                // positional para
                //  cout<<"P : "<<currToken<<endl;
                tempPNTAB.push_back(currToken);
            }
        }
        PP = tempPNTAB.size() - KP;
        PNTAB.push_back(tempPNTAB);
        // remaining lines(body and MEND)
        for (j = lineNum + 1; j < myToken.size() && myToken[j][0] != "MEND"; j++)
        {
            vector<string> V1;
            for (int i = 0; i < myToken[j].size(); i++)
            {
                int index = deal(myToken[j][i], PNTAB.size() - 1);
                if (index != -1)
                { // parameter
                    V1.push_back(" (P," + to_string(index) + ")");
                    // cout<<" (P,"<<index<<")\t";
                }
                else
                { // non-para(registers)
                    V1.push_back(myToken[j][i]);
                    // cout<<myToken[j][i] <<"\t ";
                }
            }
            MDT.push_back(V1);
            cout << endl;
        }
        MDT.push_back({"MEND"});
        MNTAB.push_back(make_tuple(name, PP, KP, MDTP, KDTP));
        // displayAll();
        return j;
    }

    void expandMacro(vector<string> currSentence, ofstream &opFile)
    {

        int index = findInMNT(currSentence[0]);
        int numPP = get<1>(MNTAB[index]);
        int numKP = get<2>(MNTAB[index]);
        int MDTP = get<3>(MNTAB[index]);
        int KDTP = get<4>(MNTAB[index]);
        //---------make APTAB-------------------------
        vector<string> APTAB(numKP + numPP, "NULL");
        // push PP
        int i;
        for (i = 1; i <= numPP; i++)
        {
            // cout<<"(PP)"<<currSentence[i]<<" ";
            APTAB[i - 1] = currSentence[i];
        }

        // determine keyword then push(KP with val)
        for (; i < currSentence.size(); i++)
        {
            // cout<<"(KP)"<<currSentence[i]<<" ";
            auto loc = currSentence[i].find("=");
            string value = currSentence[i].substr(loc + 1, currSentence[i].length() - loc);
            string keyword = currSentence[i].substr(0, loc);
            APTAB[getKeywordIndex(keyword, index)] = value;
        }
        // default values(KP w/o val)
        for (int i = 0; i < APTAB.size(); i++)
        {
            if (APTAB[i] == "NULL")
            {
                string key = PNTAB[index][i];
                APTAB[i] = getValueFromKDTAB(key, KDTP);
            }
        }
        displayAPTAB(get<0>(MNTAB[index]), APTAB);
        //---------------------------APTAB made-----------
        for (int i = MDTP; MDT[i][0] != "MEND"; i++)
        {
            for (int j = 0; j < MDT[i].size(); j++)
            {

                string instruct = MDT[i][j];

                if (instruct.find("(") != string::npos)
                {
                    int temp = stoi(instruct.substr(4, 1));
                    opFile << APTAB[temp - 1] << " ";
                }
                else
                    opFile << instruct << " ";
            }
            opFile << endl;
        }
    }
    void pass1()
    {
        for (int i = 0; i < myToken.size(); i++)
        {
            vector<string> curr = myToken[i];
            for (int j = 0; j < myToken[i].size(); j++)
            {
                if (curr[j] == "MACRO")
                {
                    i = storeDefination(i + 1);
                    break;
                }
            }
        }
    }
    void pass2()
    {
        ofstream opFile("expandes_Code.txt", ios::out);
        pass1();
        displayAll();
        for (int i = 0; i < myToken.size(); i++)
        {
            vector<string> curr = myToken[i];
            for (int j = 0; j < myToken[i].size(); j++)
            {
                // cout<<"I :"<<i<<endl;

                if (curr[j] == "MACRO")
                {
                    // cout<<myToken[i+1][0]<<endl;
                    i = i + 1 + getMacroLength(myToken[i + 1][0]);
                    break;
                }
                else if (findInMNT(curr[j]) != -1)
                {
                    // cout<<i<<" (E):\n";
                    expandMacro(curr, opFile);
                    break;
                }
                else
                {
                    /// write directly into source code
                    opFile << curr[j] << " ";
                }
            }
            opFile << endl;
        }
    }
};
int main()
{
    cout << "hello" << endl;
    macro obj;
    // obj.displayToken();
    // obj.storeDefination(1);
    obj.pass2();

    return 0;
}