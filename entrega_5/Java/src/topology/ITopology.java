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
public interface ITopology
{
    public void init(int size);
    public void setGBest(double val, ArrayList<Particle> vec);
    
    public void setFitAt(int pos, double fit);
    public double getBest();
}
