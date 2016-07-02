/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main_src;

import algorithm.AlgorithmEnum;
import java.util.ArrayList;
import topology.TopologyEnum;
import velocity.VelocityEnum;

/**
 *
 * @author Geraldo e Iago
 */
public class Enxames_Entrega {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int partAmount = 50;
        int dimAmount = 2;
        int maxEpoch = 10000;
        Swarm swarm = new Swarm(partAmount, dimAmount, maxEpoch, TopologyEnum.STAR, AlgorithmEnum.PROJECT, VelocityEnum.CLERC);
        ArrayList output = swarm.psoAlg();
        
        String out = "";
        for(int i=0, size = output.size(); i<size; i++)
        {
            out += output.get(i)+"\n";
        }
        out = out.substring(0, out.length()-1);
        ProjectIO io = new ProjectIO();
        io.writeFile("saida.csv", out);
    }
}
