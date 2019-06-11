package a;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JSlider;
import java.awt.BorderLayout;
import javax.swing.JTextArea;
import javax.swing.JList;
import javax.swing.JTextPane;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.FlowLayout;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Component;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.AbstractAction;
import javax.swing.Action;
import java.awt.Color;

public class Mframe {

	private JFrame frmLoginScreen;
	private JFrame SFrame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Mframe window = new Mframe();
					window.frmLoginScreen.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Mframe() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmLoginScreen = new JFrame();
		frmLoginScreen.setTitle("Login Screen");
		frmLoginScreen.setBounds(100, 100, 387, 235);
		frmLoginScreen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmLoginScreen.getContentPane().setLayout(null);
		
		JComboBox comboBox = new JComboBox();
		comboBox.setModel(new DefaultComboBoxModel(new String[] {"\u00D6\u011Frenci Giri\u015Fi", "\u00D6\u011Fretmen Giri\u015Fi", "Veli Giri\u015Fi"}));
		comboBox.setToolTipText("AAAAAA");
		comboBox.setBounds(95, 25, 243, 20);
		frmLoginScreen.getContentPane().add(comboBox);
		
		JLabel lblGiriTipi = new JLabel("Giri\u015F Tipi");
		lblGiriTipi.setBounds(31, 25, 64, 20);
		frmLoginScreen.getContentPane().add(lblGiriTipi);
		
		JButton btnNewButton = new JButton("\u00C7\u0131k\u0131\u015F");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});
		btnNewButton.setBounds(106, 68, 100, 36);
		frmLoginScreen.getContentPane().add(btnNewButton);
		
		JButton button = new JButton("Giri\u015F Yap");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (comboBox.getSelectedIndex()==0) {
					System.out.println("a");
				}
				else if (comboBox.getSelectedIndex()==1) {
					System.out.println("b");
					frmLoginScreen.dispose();
					Öðretmen_Frame callframe = new Öðretmen_Frame();
					callframe.setVisible(true);
					
					
				}
				else if (comboBox.getSelectedIndex()==2) {
					System.out.println("c");
				}
				
			}
		});
		button.setBounds(224, 68, 100, 36);
		frmLoginScreen.getContentPane().add(button);
		frmLoginScreen.setVisible(true);
	}
	
}
