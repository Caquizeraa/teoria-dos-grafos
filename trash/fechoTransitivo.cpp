#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void marcaVisitadosFecho(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int vertice, vector<bool>& visitados){
    for (auto& elemento : listaAdj[vertice])
    {
        int vizinho = elemento.second.first;
        if (!visitados[vizinho])
        {
            marcaVisitadosFecho(listaAdj, vizinho, visitados);
        }
    }
}

vector <int> fechoTrans(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int qtdVertices){
    vector<bool> visitadosBool(qtdVertices, false);
    vector<int> fecho;

    marcaVisitadosFecho(listaAdj, 0, visitadosBool);
    for (int i = 0; i < visitadosBool.size(); i++)
    {
        if(visitadosBool[i] == true) fecho.push_back(i);
    }

    sort(fecho.begin(), fecho.end());
    return fecho;
}