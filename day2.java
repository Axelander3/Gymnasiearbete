
import sun.misc.IOUtils;

import java.io.*;
import java.util.Scanner;

/**
 * Created by alexander on 2017-11-15.
 */
public class day2 {;

    public static void main(String[] args) throws IOException {


        String[] lines = new String[1000];

        int totalFeet = 0;

        int totalRibbonFeet = 0;

        BufferedReader br = new BufferedReader(new FileReader("/home/alexander/IdeaProjects/Gymnasiearbete/src/day2.txt"));
        int linenr = 0;
        String line = null;
        while ((line = br.readLine()) != null) {
            lines[linenr] = line;
            linenr++;
        }
        br.close();

        for (String s : lines) {
            String[] split = s.split("x");
            int l = Integer.parseInt(split[0]);
            int w = Integer.parseInt(split[1]);
            int h = Integer.parseInt(split[2]);
            totalFeet += getAmountFeet(l, w, h);
            totalRibbonFeet +=(getSmallestPerimiter(l, w, h) + getCubic(l, w, h));



        }

        System.out.println(totalFeet);
        System.out.println(totalRibbonFeet);
    }

    public static int getAmountFeet(int l, int w, int h) {
        return ((2*l*w) + (2*w*h) + (2*h*l) + smallest(l*w, w*h, h*l));
    }

    public static int smallest(int lw, int wh, int hl) {
        if ((lw < wh) && (lw < hl)) {
            return lw;
        } else if (wh < hl) {
            return wh;
        } else {
            return hl;
        }
    }

    public static int getSmallestPerimiter(int l, int w, int h) {
        int omkr1, omkr2, omkr3;
        omkr1 = 2*(h+w);
        omkr2 = 2*(l+h);
        omkr3 = 2*(l+w);
        return smallest(omkr1, omkr2, omkr3);
    }

    public static int getCubic(int l, int w, int h) {
        return l*w*h;
    }

}
