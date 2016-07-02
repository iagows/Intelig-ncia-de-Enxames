/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main_src;

import java.util.ArrayList;

/**
 *
 * @author Geraldo e Iago
 */
public class Particle
{
    private ArrayList data;
    private ArrayList pBest;
    private ArrayList gBest;
    private ArrayList velocity;
    private double fitness;
    
    private double radius;
    private String name;
    private boolean aerosol;
    private int id;
    public Particle(int id, int dataSize, double radius, String name, boolean isAerosol)
    {
        this.id = id;
        this.radius = radius;
        this.name = name;
        this.aerosol = isAerosol;
        this.fitness = Double.MAX_VALUE;
        this.initVectors(dataSize);
    }
    
    /**
     * Cria se baseando em uma doença
     * @param disease
     * @param dataSize 
     * @param id 
     */
    public Particle(Disease disease, int dataSize, int id)
    {
        this.id = id;
        this.radius = disease.isAerosol() ? 0:1;
        this.name = disease.getName();
        this.aerosol = disease.isAerosol();
        this.fitness = Double.MAX_VALUE;
        this.initVectors(dataSize);
    }
    
    private void initVectors(int dataSize)
    {
        this.data = new ArrayList();
        this.pBest = new ArrayList();
        this.velocity = new ArrayList();
        this.gBest = new ArrayList();
        for(int i = 0; i< dataSize; i++)
        {
            //posição inicial zero só para o array não ficar vazio
            data.add(0.);
            pBest.add(0.);
            gBest.add(0.);
            velocity.add(0.);
        }
    }
    
    public int getId() { return this.id; }
    
    @Override
    public String toString()
    {
        String out = "(";
        out += this.data.get(0) + ","+this.data.get(1)+","+(this.isAerosol() ? "a": "g");
        out += ")";
        return out;
    }
    
    public boolean isAerosol()
    {
        return this.aerosol;
    }
    
    public double getData(int pos)
    {
        return (double)this.data.get(pos);
    }
    
    public ArrayList getData()
    {
        return this.data;
    }
    
    public void setData(int pos, double val)
    {
        this.data.set(pos, val);
    }
    
    public double getPBest(int pos)
    {
        return (double)this.data.get(pos);
    }
    
    public void setPBest(int pos, double val)
    {
        this.pBest.set(pos, val);
    }
    
    public void setPBest()
    {
        this.pBest = (ArrayList) this.data.clone();//considera q a posição atual é a melhor da partícula
    }
    
    public double getVelocity(int pos)
    {
        return (double)this.velocity.get(pos);
    }
    
    public void setVelocity(int pos, double val)
    {
        this.velocity.set(pos, val);
    }
    
    public double getFitness()
    {
        return this.fitness;
    }
    
    public void setFitness(double val)
    {
        this.fitness = val;
    }
    
    public int size()
    {
        return this.data.size();
    }
    
    public double getRadius()
    {
        return this.radius;
    }
    
    public String getName()
    {
        return this.name;
    }
    
    public ArrayList getGBest()
    {
        return this.gBest;
    }
    
    public double getGBest(int pos)
    {
        return (double)this.gBest.get(pos);
    }
    
    public void setGBest(ArrayList vec)
    {
        this.gBest = (ArrayList)vec.clone();
    }
}
