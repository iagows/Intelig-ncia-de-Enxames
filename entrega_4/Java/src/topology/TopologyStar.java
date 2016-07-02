/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package topology;

import main_src.Particle;
import java.util.ArrayList;

/**
 *
 * @author Geraldo e Iago
 */
public class TopologyStar extends AbstractTopology
{
    private double globalBestFit;
    
    public TopologyStar() { }    
    
    @Override
    public void init(int size)
    {
        super.init(size);
        this.globalBestFit = Double.MAX_VALUE;//começa com o pior caso possível
    }
    
    @Override
    public void setGBest(double val, ArrayList<Particle> vec)
    {
        this.globalBestFit = val;
        Particle best = null;
        double fit = Double.MAX_VALUE;
        for(int i=0, size=vec.size(); i<size; i++)
        {
            Particle p = vec.get(i);
            if(p.getFitness() <= fit)
            {
                best = p;
                fit = p.getFitness();
            }
        }
        for(int i=0, size=vec.size(); i<size; i++)
        {
            Particle p = vec.get(i);
            p.setGBest(best.getData());
        }
    }
    
    @Override
    public double getBest()
    {
        return this.globalBestFit;
    }
}
