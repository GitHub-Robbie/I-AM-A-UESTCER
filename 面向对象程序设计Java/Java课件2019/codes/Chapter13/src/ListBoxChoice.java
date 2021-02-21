/**
   Ô´³ÌÐò£ºListBoxChoice.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class ListBoxChoice extends Applet
                    implements ActionListener, ItemListener {
    Label Disp = new Label("No Selection", Label.CENTER);
    String[] fName = {"Fancy", "TimesRoman",
                          "Courier", "Sanserif"};
    int[] fStyle = {Font.PLAIN, Font.ITALIC, Font.BOLD};
    int size = 10, style = 0;
    String name = "Fancy";
    boolean bChange = false;
    Button b;
        public void init() {
        setLayout(new BorderLayout());
        Panel ep = new Panel();
        GridBagLayout gb = new GridBagLayout();
        GridBagConstraints gbc = new GridBagConstraints();
        ep.setLayout(gb);
        Choice fontChoice = new Choice();
        for(int i=0; i<fName.length; i++) {
            fontChoice.addItem(fName[i]);
        }
        fontChoice.select(fName[0]);
        fontChoice.addItemListener(this);
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gb.setConstraints(fontChoice,gbc);
        ep.add(fontChoice);
        List listItem = new List(5, false);
        for(int i=0; i < 6; i++) {
            listItem.addItem(Integer.toString(10+i*4));
        }
        listItem.addItemListener(this);
        listItem.addActionListener(this);
        gbc.gridy ++;
        gb.setConstraints(listItem,gbc);
        ep.add(listItem);
        CheckboxGroup cbg;
        Checkbox cbPlain, cbItalic, cbBold;
        cbg = new CheckboxGroup();
        cbPlain = new Checkbox("Plain", cbg, true);
        cbItalic = new Checkbox("Italic", cbg, false);
        cbBold = new Checkbox("Bold", cbg, false);
        cbPlain.addItemListener(this);
        cbItalic.addItemListener(this);
        cbBold.addItemListener(this);
        Panel pp = new Panel();
        pp.setLayout(new GridLayout(1, 3));
        pp.add(cbPlain);
        pp.add(cbItalic);
        pp.add(cbBold);
        gbc.gridy ++;
        gb.setConstraints(pp,gbc);
        ep.add(pp);
        add("East", ep);
        b = new Button("Display");
        add(b);
        b.addActionListener(this);
        add("South", b);
        b.setEnabled(false);
        validate();
        fontChoice.requestFocus();
        Disp.setFont(new Font("Courier", Font.BOLD, 20));
        add("Center", Disp);
    }
    public void itemStateChanged(ItemEvent e) {
        if(e.getItemSelectable() instanceof List) {
            List lt = (List)e.getItemSelectable();
            String itemStr = lt.getSelectedItem();
            size = (new Integer(itemStr)).intValue();
            bChange = true;
            b.setEnabled(true);
        } else if(e.getItemSelectable() instanceof Choice){
            name = (String)e.getItem();
            bChange = true;
            b.setEnabled(true);
        } else if(e.getItemSelectable() instanceof Checkbox) {
            String cb = (String)e.getItem();
            if(cb.equals("Plain")) {
                style = 0;
            } else if(cb.equals("Italic")) {
                style = 1;
            } else if(cb.equals("Bold")) {
                style = 2;
            } 
            bChange = true;
            b.setEnabled(true);
        }
    }
    public void actionPerformed(ActionEvent e) {
        String arg = e.getActionCommand();
        if (arg.equals("Display")) {
            if(bChange) {
              Disp.setFont(new Font(name, fStyle[style], size));
              Disp.setText(name + " " + size);
              bChange = false;
              b.setEnabled(false);
            }
        } else  {
            size = (new Integer(arg)).intValue();
            Disp.setFont(new Font(name, fStyle[style], size));
            Disp.setText(name + " " + size);
        }
    }
}
