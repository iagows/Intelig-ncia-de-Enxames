/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main_src;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.stream.Stream;

/**
 *
 * @author Geraldo e Iago
 */
public class ProjectIO
{
    public ProjectIO()
    {
        
    }
    
    public void writeFile(String file, String text)
    {
        try(FileWriter writer = new FileWriter(file))
        {
            writer.write(text);
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }
    
    /**
     * Lê o arquivo para gerar as partículas
     * @param file
     * @return 
     */
    public ArrayList<Disease> readFile(String file)
    {
        ArrayList<Disease> out = new ArrayList<>();
        
        try (Stream<String> stream = Files.lines(Paths.get(file))){
            stream.forEach((string) -> {
                Disease d = this.fromLine(string);
                if(d!=null)
                {
                    out.add(d);
                }
            });
        } catch (Exception e) {
            System.out.println(e.toString());
        }
        return out;
    }
    
    private Disease fromLine(String line)
    {
        Disease d = null;
        
        if(!line.startsWith("%"))//ignorar comentários
        {
            String[] arr = line.split(",");
            String cid = arr[0];
            String name = arr[1];
            String spread = arr[2];
            
            d = new Disease(cid, name, spread);
        }
                
        return d;
    }
}
