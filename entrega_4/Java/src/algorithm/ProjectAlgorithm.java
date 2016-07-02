/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithm;

import main_src.Particle;
import java.util.ArrayList;

/**
 *
 * @author Geraldo e Iago
 */
public class ProjectAlgorithm extends AbstractAlgorithm
{

    @Override
    public void init() {
        this.max = 10;
        this.min = -max;
        this.vMax = 2;//2*this.max;
    }
    
    /**
     *
     * @param part Partícula a ser analisada
     * @param others As outras partículas
     * @return 0 se ambas forem !aerosol e dist>1 
     *         1/r caso contrário
     */
    @Override
    public double fitness(Particle part, ArrayList<Particle> others)
    {
        double out = 0;
        
        //para cada outra partícula
        for (int i=0; i<others.size(); i++)
        {
            Particle other = others.get(i);
            if(other.getId() == part.getId()) continue;
            double sqrt = 0;
            //para cada dimensão da partícula
            for(int j=0; j<part.size(); j++)
            {
                //pegar o quadrado da diferença
                int diff = (int) (part.getData(j) - other.getData(j));
                sqrt += Math.pow(diff, 2);
            }
            //tirando a raiz, tem-se a distância euclidiana
            sqrt = Math.sqrt(sqrt);
            
            /*
            Gotícula tem alcance máximo de 1m
            Aerosol tem alcance indefinido
            */
            if(!part.isAerosol() && !other.isAerosol() && sqrt > 1)
            {
                //sendo ambas de gotícula (!aerosol), então basta que a distância seja maior que um
                out += 0; //premiando por estar em distância adequada
            }
            else
            {
                if(sqrt==0) sqrt += 10;
                //aqui, pelo menos uma é aerosol ou se encontram muito próximas
                //quanto menor a distância, maior a penalização
                out += 1/sqrt;//penaliza-se
            }
        }
        
        return out;
    }

    @Override
    public double getInitialBest()
    {
        return 0;
    }
}
