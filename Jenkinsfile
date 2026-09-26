pipeline {
    agent any

    environment {
        APP_NAME = 'MyApplication'
    }

    stages {
        stage('Build') {
            steps {
                echo "Building ${env.APP_NAME}"
                sh 'g++ -std=c++20 -o main main.cpp Account.cpp'
            }
        }

        stage('Test') {
            steps {
                echo 'Testing the application'
                sh './main'
            }
        }

        stage('Deploy') {
            steps {
                echo 'No deployment has been configured yet'
                // Add the real deployment command here.
            }
        }
    }

    post {
        success {
            echo 'Build, test, and deployment completed successfully'
            echo "Build number: ${env.BUILD_NUMBER}"
            echo "Build URL: ${env.BUILD_URL}"

            writeFile(
                file: "build-${env.BUILD_NUMBER}.txt",
                text: "SUCCESS: ${env.BUILD_NUMBER} - ${env.BUILD_URL}\n"
            )

            archiveArtifacts(
                artifacts: "build-${env.BUILD_NUMBER}.txt, main",
                fingerprint: true
            )
        }

        failure {
            echo 'One or more stages failed'
        }

        cleanup {
            deleteDir()
        }
    }
}
