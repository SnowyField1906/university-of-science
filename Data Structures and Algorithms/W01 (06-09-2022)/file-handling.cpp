#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include<iomanip>

using namespace std;

const string SUBJECTS[] = {"maths", "literature", "physics", "chemistry",
                         "biology", "history", "geography",
                         "civic_education", "natural_science",
                         "social_science", "foregin_language"};


struct Examinee {
    string id;
    float maths, literature, physics, chemistry, biology, history,
        geography, civic_education, natural_science, social_science,
        foregin_language;
};

// Read the information of one examinee
Examinee readExaminee(string line_info) {
    Examinee examinee;
    stringstream info(line_info);

    string subjects[11];
    string name;
    getline(info, examinee.id, ',');
    getline(info, name, ',');
    for (int i = 0; i < 11; i++) {
        string a;
        getline(info, subjects[i], ',');
    }

    examinee.maths = subjects[0] == "" ? 0 : stof(subjects[0]);
    examinee.literature = subjects[1] == "" ? 0 : stof(subjects[1]);
    examinee.physics = subjects[2] == "" ? 0 : stof(subjects[2]);
    examinee.chemistry = subjects[3] == "" ? 0 : stof(subjects[3]);
    examinee.biology = subjects[4] == "" ? 0 : stof(subjects[4]);
    examinee.history = subjects[5] == "" ? 0 : stof(subjects[5]);
    examinee.geography = subjects[6] == "" ? 0 : stof(subjects[6]);
    examinee.civic_education = subjects[7] == "" ? 0 : stof(subjects[7]);
    examinee.natural_science = subjects[8] == "" ? 0 : stof(subjects[8]);
    examinee.social_science = subjects[9] == "" ? 0 : stof(subjects[9]);
    examinee.foregin_language = subjects[10] == "" ? 0 : stof(subjects[10]);

    return examinee;
}

vector<Examinee> readExamineeList(string file_name) {
    ifstream file(file_name);
    vector<Examinee> examinees;

    string first;
    getline(file, first);

    string line_info;
    while(getline(file, line_info)) {
        examinees.push_back(readExaminee(line_info));
    }

    return examinees;
}

void writeTotalScore(vector<Examinee> examinee_list, string out_file_name) {
    ofstream out_file(out_file_name);

    out_file << "ID, Compulsory, Natural, Social" << endl;
    
    for (int i = 0; i < examinee_list.size(); i++) {
        float compulsory_score , natural_science, social_science;

        compulsory_score = examinee_list[i].maths + examinee_list[i].literature + examinee_list[i].foregin_language;

        natural_science = examinee_list[i].physics + examinee_list[i].chemistry + examinee_list[i].biology;

        social_science = examinee_list[i].history + examinee_list[i].geography + examinee_list[i].civic_education;

        out_file << examinee_list[i].id << " " << compulsory_score << " " << natural_science << " " << social_science << endl;
    }

}


int main() {
    vector<Examinee> examinees = readExamineeList("data.txt");

    cout << left << setw(10) << "ID" << setw(7) << "Mat." << setw(7) << "Lit." << setw(7)
    << "Phy." << setw(7) << "Che." << setw(7) << "Bio." << setw(7)
    << "His." << setw(7) << "Geo." << setw(7) << "C.E." << setw(7)
    << "N.S." << setw(7) << "S.S." << setw(7) << "F.L." << endl;

    writeTotalScore(examinees, "total_score.txt");


    for (int i = 0; i < examinees.size() - 1; i++) {
        cout << left << setw(10) << examinees[i].id << setw(7)
        << examinees[i].maths << setw(7) << examinees[i].literature << setw(7)
        << examinees[i].physics << setw(7) << examinees[i].chemistry << setw(7)
        << examinees[i].biology << setw(7) << examinees[i].history << setw(7)
        << examinees[i].geography << setw(7) << examinees[i].civic_education << setw(7)
        << examinees[i].natural_science << setw(7) << examinees[i].social_science << setw(7)
        << examinees[i].foregin_language << endl;
    }

    return 0;
}
