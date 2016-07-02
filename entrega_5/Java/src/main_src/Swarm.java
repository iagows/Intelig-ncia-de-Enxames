/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main_src;

import algorithm.AlgorithmEnum;
import algorithm.AlgorithmFactory;
import algorithm.IAlgorithm;
import java.time.Clock;
import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;
import topology.ITopology;
import topology.TopologyEnum;
import topology.TopologyFactory;
import velocity.IVelocity;
import velocity.VelocityEnum;
import velocity.VelocityFactory;

/**
 *
 * @author Geraldo e Iago
 */
public class Swarm
{
    private int particleAmount;
    private int dimensionAmount;
    private int maxEpoch;
    
    private ArrayList<Particle> particles;
    
    private int epoch;
    
    private ITopology topology;
    private IAlgorithm algorithm;
    private IVelocity velocity;
    
    public Swarm(int partAmount, int dimAmount, int maxEpoch, TopologyEnum top,
            AlgorithmEnum alg, VelocityEnum vel)
    {
        this.particleAmount = partAmount;
        this.dimensionAmount = dimAmount;
        this.maxEpoch = maxEpoch;
        
        TopologyFactory topFac = new TopologyFactory(top);
        this.topology = topFac.get();
        this.topology.init(partAmount);
        
        AlgorithmFactory algFac = new AlgorithmFactory(alg);
        this.algorithm = algFac.get();
        
        VelocityFactory velFac = new VelocityFactory(vel);
        this.velocity = velFac.get();
    }
    
    public ArrayList psoAlg()
    {
        ArrayList outputFit = new ArrayList();
        ArrayList positions = new ArrayList();
        //inicializando
        this.initialize();
        
        int size = this.particles.size();
        do
        {
            double lastFit = Double.MAX_VALUE;
            if(outputFit.size()>0)
                lastFit = (double) outputFit.get(outputFit.size()-1);
            //Temos que calcular a soma dos fitness individuais
            //pra ver se a melhora foi geral
            double fitnessSum = 0;
            //calcula o fitness individual
            for(int i=0; i<size; i++)
            {
                Particle current = this.particles.get(i);
                double fit = this.algorithm.fitness(current, particles);
                if(fit< current.getFitness())
                {
                    current.setFitness(fit);
                    current.setPBest();
                }
                //this.topology.setFitAt(i, fit);
                //somando ao fitness dessa iteração
                fitnessSum += fit;
            }
            
            
            /*
            Se o fitnesse melhorou, então:
            atualize o melhor
            armazene
            calcule velocidade
            movimente
            */
            if(fitnessSum < this.topology.getBest())
            {
                lastFit = fitnessSum;
                this.topology.setGBest(fitnessSum, particles);
                for(int i=0; i<size; i++)
                {
                    Particle current = this.particles.get(i);

                    for(int j=0; j<this.dimensionAmount; j++)
                    {
                        //this.calculateVelocityW(current, j);
                        this.velocity.calculate(current, j, this.algorithm.getVMax(), epoch, maxEpoch);
                        this.updatePosition(current, j);
                    }
                }
                positions.add(particlesToString());
            }
            outputFit.add(lastFit);
            
            //movimentação aleatória
            for(int i=0; i<size; i++)
            {
                Particle current = this.particles.get(i);
                randomSpeed(current);
                for(int j=0; j<this.dimensionAmount; j++)
                {
                    randomSpeed(current);
                    this.updatePosition(current, j);
                }
            }
            
            
            epoch++;
        }while(this.epoch < this.maxEpoch);//para no limite || trocar para condição do problema, i.e. N ciclos parado
        
        /* imprimindo a variação de fit */
        String out = "";
        for(int i=0, s = outputFit.size(); i<s; i++)
        {
            out += outputFit.get(i)+"\n";
        }
        out = out.substring(0, out.length()-1);
        ProjectIO io = new ProjectIO();
        io.writeFile("fit.csv", out);
        
        return positions;
    }
    
    private String particlesToString()
    {
        String out = "";
        for(int i=0, size = this.particles.size(); i<size; i++)
        {
            out += this.particles.get(i).toString()+";";
        }
        out = out.substring(0, out.length()-1);
        return out;
    }
    
    private double random(double max, double min)
    {
        return ThreadLocalRandom.current().nextDouble((int)min, (int)max);
    }
    
    private void randomSpeed(Particle part)
    {
        int size = this.dimensionAmount;
        for(int i=0; i<size; i++)
        {
            double _max = this.algorithm.getVMax();
            double randomSpeed = random(_max, -_max);
            if(randomSpeed==0) randomSpeed++;
            part.setVelocity(i, randomSpeed);
        }
    }
    
    /**
     *  Inicializa as partículas em posições aleatórias e com velocidades aleatórias.
     */
    private void initialize()
    {
        this.epoch = 0;
        this.algorithm.init();
        
        ProjectIO io = new ProjectIO();
        ArrayList<Disease> diseases = io.readFile("entrada.csv");
        
        int id = 0;
        this.particles = new ArrayList<>();
        for(int i=0, size = diseases.size(); i<size; i++)
        {
            Particle p = new Particle(diseases.get(i), this.dimensionAmount, id++);
            p = randomize(p);
            this.particles.add(p);
        }
        
        //criando as partículas
        for(int i=0, size=particleAmount-diseases.size(); i<size; i++)
        {
            int rand = (int) (Math.random()*diseases.size());
            Particle p = new Particle(diseases.get(rand), this.dimensionAmount, id++);
            p = randomize(p);
            this.particles.add(p);
        }
    }
    
    private Particle randomize(Particle p)
    {
        //posicionando aleatoriamente
        for(int j=0; j<dimensionAmount; j++)
        {
            int randomVal = (int)random(this.algorithm.getMax(), this.algorithm.getMin());
            p.setData(j, randomVal);
            p.setPBest(j, randomVal);//o melhor é o inicial
        }
        this.randomSpeed(p);
        
        return p;
    }
    /*
    private void calculateVelocityW(Particle part, int pos)
    {
        double w= 0.8;
        double c1 = 2.05;
        double c2 = 2.05;
        
        double rand1 = random(1, 0);
        double rand2 = random(1, 0);
        
        double v1 = c1 * rand1 * (part.getPBest(pos) - part.getData(pos));
        double v2 = c2 * rand2 * (part.getGBest(pos) - part.getData(pos));
        double _velocity = w * part.getVelocity(pos) + v1 + v2;
        
        //clamping
        double max = this.algorithm.getVMax();
        if(_velocity> max)
            _velocity = max;
        if(_velocity< -max)
            _velocity = -max;
        
        part.setVelocity(pos, _velocity);
    }
    */
    private void updatePosition(Particle part, int pos)
    {
        double vel = part.getVelocity(pos);//valor já atualizado
        double oldPos = part.getData(pos);
        
        double newPos = vel+oldPos;
        if(newPos < this.algorithm.getMin())
            newPos = this.algorithm.getMin();
        if(newPos > this.algorithm.getMax())
            newPos = this.algorithm.getMax();
        
        part.setData(pos, newPos);
    }
}