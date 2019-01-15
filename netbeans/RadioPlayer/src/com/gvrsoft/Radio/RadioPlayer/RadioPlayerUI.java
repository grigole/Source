/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.gvrsoft.Radio.RadioPlayer;

import org.apache.log4j.PropertyConfigurator;
import org.apache.log4j.Logger;

/**
 *
 * @author grigole
 */
public class RadioPlayerUI extends javax.swing.JFrame {

    /**
     * Creates new form RadioPlayerUI
     */
    public RadioPlayerUI() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabelTitle = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jListStations = new javax.swing.JList<>();
        jButtonAdd = new javax.swing.JButton();
        jButtonPlay = new javax.swing.JButton();
        jMenuBarMain = new javax.swing.JMenuBar();
        jMenuFile = new javax.swing.JMenu();
        jMenuItemClose = new javax.swing.JMenuItem();
        jMenuAction = new javax.swing.JMenu();
        jMenuItemPlay = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabelTitle.setFont(new java.awt.Font("Serif", 1, 36)); // NOI18N
        jLabelTitle.setText("Greg's Radio Player");

        jListStations.setModel(new javax.swing.AbstractListModel<String>() {
            String[] strings = { "CFRB 1010", "Q107" };
            public int getSize() { return strings.length; }
            public String getElementAt(int i) { return strings[i]; }
        });
        jScrollPane1.setViewportView(jListStations);

        jButtonAdd.setText("Add Station");

        jButtonPlay.setText("Play");

        jMenuFile.setText("File");

        jMenuItemClose.setText("Close");
        jMenuItemClose.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItemCloseActionPerformed(evt);
            }
        });
        jMenuFile.add(jMenuItemClose);

        jMenuBarMain.add(jMenuFile);

        jMenuAction.setText("Actions");

        jMenuItemPlay.setText("Play");
        jMenuItemPlay.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItemPlayActionPerformed(evt);
            }
        });
        jMenuAction.add(jMenuItemPlay);

        jMenuBarMain.add(jMenuAction);

        setJMenuBar(jMenuBarMain);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabelTitle, javax.swing.GroupLayout.PREFERRED_SIZE, 418, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 104, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jButtonPlay)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButtonAdd)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jLabelTitle, javax.swing.GroupLayout.PREFERRED_SIZE, 41, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jButtonAdd)
                    .addComponent(jButtonPlay))
                .addGap(0, 46, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jMenuItemCloseActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemCloseActionPerformed

        logger.info( "Calling exit( 0 )" );
        System.exit( 0 );

    }//GEN-LAST:event_jMenuItemCloseActionPerformed

    private void jMenuItemPlayActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemPlayActionPerformed

        logger.info( "Calling play()" );

    }//GEN-LAST:event_jMenuItemPlayActionPerformed

    static Logger logger = Logger.getLogger( RadioPlayerUI.class );

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(RadioPlayerUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(RadioPlayerUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(RadioPlayerUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(RadioPlayerUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        PropertyConfigurator.configure( "src/com/gvrsoft/Radio/RadioPlayer/log4j.properties" );

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new RadioPlayerUI().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonAdd;
    private javax.swing.JButton jButtonPlay;
    private javax.swing.JLabel jLabelTitle;
    private javax.swing.JList<String> jListStations;
    private javax.swing.JMenu jMenuAction;
    private javax.swing.JMenuBar jMenuBarMain;
    private javax.swing.JMenu jMenuFile;
    private javax.swing.JMenuItem jMenuItemClose;
    private javax.swing.JMenuItem jMenuItemPlay;
    private javax.swing.JScrollPane jScrollPane1;
    // End of variables declaration//GEN-END:variables
}
