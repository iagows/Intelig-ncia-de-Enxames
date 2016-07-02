/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main_src;

/**
 *
 * @author Geraldo e Iago
 */
public class Disease {
    private final String cid;
    private final String name;
    private final String spread;
    public Disease(String cid, String name, String spread)
    {
        this.cid = cid;
        this.name = name;
        this.spread = spread;
    }
    
    public String getCID(){ return this.cid; }
    public String getName() { return this.name; }
    public boolean isAerosol() { return this.spread.compareTo("a") == 0; }
}
